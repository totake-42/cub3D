/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:00:00 by totake            #+#    #+#             */
/*   Updated: 2026/02/21 17:16:08 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Structure to hold ray casting result
 * Contains both distance and wall side information
 */
typedef struct s_ray_result
{
	double			perp_wall_dist;
	int				side;
}					t_ray_result;

/*
 * DDA (Digital Differential Analyzer) algorithm
 * Cast a single ray and return the distance to the wall and which side was hit
 */
static t_ray_result	cast_single_ray(t_cub3d *app, double ray_dir_x,
		double ray_dir_y)
{
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	double			perp_wall_dist;
	t_ray_result	result;

	map_x = (int)app->player.pos_x;
	map_y = (int)app->player.pos_y;
	delta_dist_x = fabs(1.0 / ray_dir_x);
	delta_dist_y = fabs(1.0 / ray_dir_y);
	if (ray_dir_x < 0)
	{
		step_x = -1;
		side_dist_x = (app->player.pos_x - map_x) * delta_dist_x;
	}
	else
	{
		step_x = 1;
		side_dist_x = (map_x + 1.0 - app->player.pos_x) * delta_dist_x;
	}
	if (ray_dir_y < 0)
	{
		step_y = -1;
		side_dist_y = (app->player.pos_y - map_y) * delta_dist_y;
	}
	else
	{
		step_y = 1;
		side_dist_y = (map_y + 1.0 - app->player.pos_y) * delta_dist_y;
	}
	hit = 0;
	while (hit == 0)
	{
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += delta_dist_x;
			map_x += step_x;
			side = 0;
		}
		else
		{
			side_dist_y += delta_dist_y;
			map_y += step_y;
			side = 1;
		}
		if (map_x >= 0 && map_x < app->map_data->grid_width && map_y >= 0
			&& map_y < app->map_data->grid_height)
		{
			if (app->map_data->grid[map_y][map_x] == '1')
				hit = 1;
		}
		else
		{
			hit = 1;
		}
	}
	if (side == 0)
		perp_wall_dist = (map_x - app->player.pos_x + (1 - step_x) / 2)
			/ ray_dir_x;
	else
		perp_wall_dist = (map_y - app->player.pos_y + (1 - step_y) / 2)
			/ ray_dir_y;
	result.perp_wall_dist = perp_wall_dist;
	result.side = side;
	return (result);
}

/*
 * Cast rays for all screen columns and draw vertical lines
 * if width is 1024, cast 1024 rays and draw 1024 vertical lines
 */
void	raycast_all(t_cub3d *app)
{
	int				x;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	t_ray_result	ray;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				y;
	int				wall_color;
	char			*dst;
	int				offset;

	x = 0;
	while (x < app->view->win_width)
	{
		camera_x = 2.0 * x / (double)app->view->win_width - 1.0;
		ray_dir_x = app->player.dir_x + app->player.plane_x * camera_x;
		ray_dir_y = app->player.dir_y + app->player.plane_y * camera_x;
		ray = cast_single_ray(app, ray_dir_x, ray_dir_y);
		line_height = (int)(app->view->win_height / ray.perp_wall_dist);
		draw_start = -line_height / 2 + app->view->win_height / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + app->view->win_height / 2;
		if (draw_end >= app->view->win_height)
			draw_end = app->view->win_height - 1;
		wall_color = 0xC0C0C0;
		if (ray.side == 1)
			wall_color = wall_color / 2;
		if (ray.perp_wall_dist > 10.0)
			wall_color = wall_color / 2;
		y = draw_start;
		while (y <= draw_end)
		{
			offset = y * app->view->size_line + x * (app->view->bits_per_pixel
					/ 8);
			dst = app->view->data_addr + offset;
			if (app->view->endian == 0)
			{
				dst[0] = (wall_color)&0xFF;
				dst[1] = (wall_color >> 8) & 0xFF;
				dst[2] = (wall_color >> 16) & 0xFF;
				dst[3] = 0;
			}
			else
			{
				dst[0] = (wall_color >> 16) & 0xFF;
				dst[1] = (wall_color >> 8) & 0xFF;
				dst[2] = (wall_color)&0xFF;
				dst[3] = 0;
			}
			y++;
		}
		x++;
	}
}

/*
 * Cast a single ray in the center of the screen for testing
 * Print the distance to the wall
 */
void	raycast_single(t_cub3d *app)
{
	double			ray_dir_x;
	double			ray_dir_y;
	t_ray_result	ray;
	static int		frame_count = 0;

	ray_dir_x = app->player.dir_x;
	ray_dir_y = app->player.dir_y;
	ray = cast_single_ray(app, ray_dir_x, ray_dir_y);
	if (frame_count < 5)
	{
		printf("Ray direction: (%.2f, %.2f)\n", ray_dir_x, ray_dir_y);
		printf("Distance to wall: %.2f\n", ray.perp_wall_dist);
		printf("Side: %d (0=X-side, 1=Y-side)\n", ray.side);
		printf("---\n");
		frame_count++;
	}
}
