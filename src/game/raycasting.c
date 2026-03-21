/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:00:00 by totake            #+#    #+#             */
/*   Updated: 2026/03/21 17:44:03 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_dda
{
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	int				step_x;
	int				step_y;
}					t_dda;

/*
 * Calculate the dda->side_dist_x & dda->side_dist_y
 * based on the player's position and ray direction
 *
 * dda->map_x, dda->map_y: Current grid cell in the map
 * example: pos_x = 3.5, pos_y = 2.7; map_x = 3, map_y = 2
 *
 * ray_x, ray_y: Direction of the ray
 * example: ray_x = 0, ray_y = -1; (facing north)
 *
 * dda->delta_dist_x&y: Distance of one step
 * example: dda->delta_dist_y = fabs(1.0 / ray_y) = fabs(1.0 / -1) = 1.0;
 *
 * dda->side_dist_x&y : Distance from the current position to the next side
 * example: dda->side_dist_y = (pos_y - map_y) * dda->delta_dist_y
 *        = dda->side_dist_y = (2.7 - 2) * 1.0 = 0.7 * 1.0 = 0.7
 */
static void	init_dda(t_dda *dda, t_player *p, double ray_x, double ray_y)
{
	dda->map_x = (int)p->pos_x;
	dda->map_y = (int)p->pos_y;
	dda->delta_dist_x = fabs(1.0 / ray_x);
	dda->delta_dist_y = fabs(1.0 / ray_y);
	if (ray_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (p->pos_x - dda->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0 - p->pos_x) * dda->delta_dist_x;
	}
	if (ray_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (p->pos_y - dda->map_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->map_y + 1.0 - p->pos_y) * dda->delta_dist_y;
	}
}

static int	run_dda(t_dda *dda, t_map *map)
{
	int	side;

	side = 0;
	while (1)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			side = 0;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			side = 1;
		}
		if (dda->map_x < 0 || dda->map_x >= map->grid_width || dda->map_y < 0
			|| dda->map_y >= map->grid_height)
			break ;
		if (map->grid[dda->map_y][dda->map_x] == '1')
			break ;
	}
	return (side);
}

static t_ray_result	cast_single_ray(t_cub3d *app, double ray_x, double ray_y)
{
	t_dda			dda;
	t_ray_result	r;

	init_dda(&dda, &app->player, ray_x, ray_y);
	r.side = run_dda(&dda, app->map_data);
	r.step_x = dda.step_x;
	r.step_y = dda.step_y;
	r.map_x = dda.map_x;
	r.map_y = dda.map_y;
	if (r.side == 0)
		r.perp_wall_dist = (dda.map_x - app->player.pos_x + (1 - dda.step_x)
				/ 2) / ray_x;
	else
		r.perp_wall_dist = (dda.map_y - app->player.pos_y + (1 - dda.step_y)
				/ 2) / ray_y;
	if (r.side == 0)
		r.wall_x = app->player.pos_y + r.perp_wall_dist * ray_y;
	else
		r.wall_x = app->player.pos_x + r.perp_wall_dist * ray_x;
	r.wall_x -= floor(r.wall_x);
	return (r);
}

static int	select_texture(t_ray_result *ray)
{
	if (ray->side == 0)
	{
		if (ray->step_x < 0)
			return (TEX_WEST);
		return (TEX_EAST);
	}
	if (ray->step_y < 0)
		return (TEX_NORTH);
	return (TEX_SOUTH);
}

static void	calc_draw_info(t_cub3d *app, t_ray_result *ray, t_draw_info *di,
		int tex_idx)
{
	di->line_height = (int)(app->view->win_height / ray->perp_wall_dist);
	di->draw_start = -di->line_height / 2 + app->view->win_height / 2;
	if (di->draw_start < 0)
		di->draw_start = 0;
	di->draw_end = di->line_height / 2 + app->view->win_height / 2;
	if (di->draw_end >= app->view->win_height)
		di->draw_end = app->view->win_height - 1;
	di->tex_x = (int)(ray->wall_x * app->textures[tex_idx].width);
	if (ray->side == 0 && ray->step_x > 0)
		di->tex_x = app->textures[tex_idx].width - di->tex_x - 1;
	if (ray->side == 1 && ray->step_y < 0)
		di->tex_x = app->textures[tex_idx].width - di->tex_x - 1;
}

static int	get_tex_color(t_texture *tex, int tex_x, int tex_y)
{
	char	*src;

	src = tex->data_addr + (tex_y * tex->size_line + tex_x
			* (tex->bits_per_pixel / 8));
	return (*(int *)src);
}

static void	draw_textured_column(t_cub3d *app, int x, t_draw_info *di,
		int tex_idx)
{
	int		y;
	int		tex_y;
	double	step;
	double	tex_pos;
	char	*dst;

	step = 1.0 * app->textures[tex_idx].height / di->line_height;
	tex_pos = (di->draw_start - app->view->win_height / 2 + di->line_height / 2)
		* step;
	y = di->draw_start;
	while (y <= di->draw_end)
	{
		tex_y = (int)tex_pos & (app->textures[tex_idx].height - 1);
		tex_pos += step;
		dst = app->view->data_addr + (y * app->view->size_line + x
				* (app->view->bits_per_pixel / 8));
		*(int *)dst = get_tex_color(&app->textures[tex_idx], di->tex_x, tex_y);
		y++;
	}
}

void	raycast_all(t_cub3d *app)
{
	int				x;
	double			camera_x;
	double			ray_dir[2];
	t_ray_result	ray;
	int				tex_idx;
	t_draw_info		di;

	x = 0;
	while (x < app->view->win_width)
	{
		camera_x = 2.0 * x / (double)app->view->win_width - 1.0;
		ray_dir[0] = app->player.dir_x + app->player.plane_x * camera_x;
		ray_dir[1] = app->player.dir_y + app->player.plane_y * camera_x;
		ray = cast_single_ray(app, ray_dir[0], ray_dir[1]);
		tex_idx = select_texture(&ray);
		calc_draw_info(app, &ray, &di, tex_idx);
		draw_textured_column(app, x, &di, tex_idx);
		x++;
	}
}

void	raycast_single(t_cub3d *app)
{
	t_ray_result	ray;
	static int		frame_count = 0;

	ray = cast_single_ray(app, app->player.dir_x, app->player.dir_y);
	if (frame_count < 5)
	{
		printf("Distance: %.2f, Side: %d\n", ray.perp_wall_dist, ray.side);
		frame_count++;
	}
}
