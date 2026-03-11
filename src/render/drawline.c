/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 19:05:17 by tigarashi         #+#    #+#             */
/*   Updated: 2026/03/12 01:48:04 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <math.h>

#include "render.h"
#include "cub3d.h"

void	put_pixel(t_minilibx *view, int x, int y, int color)
{
	char	*dst;
	int		offset;

	if (x < 0 || x >= view->win_width || y < 0 || y >= view->win_height)
		return ;
	offset = y * view->size_line + x * (view->bits_per_pixel / 8);
	dst = view->data_addr + offset;
	if (view->endian == 0)
	{
		dst[0] = (color) & 0xFF;
		dst[1] = (color >> 8) & 0xFF;
		dst[2] = (color >> 16) & 0xFF;
		dst[3] = 0;
	}
	else
	{
		dst[0] = (color >> 16) & 0xFF;
		dst[1] = (color >> 8) & 0xFF;
		dst[2] = (color) & 0xFF;
		dst[3] = 0;
	}	
}


void	put_pixel_three_color(t_minilibx *view, int x, int y, int color[static 3])
{
	char	*dst;
	int		offset;
	int		i;

	if (x < 0 || x >= view->win_width || y < 0 || y >= view->win_height)
		return ;
	offset = y * view->size_line + x * (view->bits_per_pixel / 8);
	dst = view->data_addr + offset;
	i = 0;
	while (i < 3)
	{
		dst[i] =  0xFF & color[i];
		i++;
	}
}

void	draw_texture_wall(t_cub3d *app, t_ray *ray, int x)
{
	int		tex_x;
	double	step;
	double	tex_pos;
	int		y;
	int		tex_y;
	double	wall_x;

	if (ray->side == 0)
		wall_x = app->player.pos_y + ray->perpwall_dist * ray->raydir_y;
	else
		wall_x = app->player.pos_x + ray->perpwall_dist * ray->raydir_x;
	wall_x -= floor(wall_x);
	tex_x =	(int)(wall_x * (double)app->texture[ray->dir].width);
	// 反転対策をする
	if (ray->dir == NORTH)
		tex_x = app->texture[ray->dir].width - tex_x - 1;
	if (ray->dir == WEST)
		tex_x = app->texture[ray->dir].width - tex_x - 1;
	step = 1.0 * app->texture[ray->dir].height / ray->line_height;
	tex_pos = (ray->draw_start - app->view->win_height / 2 + ray->line_height / 2) * step;

	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex_y = (int)tex_pos & (app->texture[ray->dir].height - 1);
		// texturが2の累乗のみ
		tex_pos += step;
		int	offset = tex_y * app->texture[ray->dir].size_line
			+ tex_x * (app->texture[ray->dir].bits_per_pixel / 8);
		int	color = *(int *)(app->texture[ray->dir].data_addr + offset);
		put_pixel(app->view, x, y, color);
		y++;
	}
}


void	drawline(t_cub3d *app, t_ray *ray, int x)
{
	int		y;


	y = 0;
	while (y < ray->draw_start)
	{
		put_pixel_three_color(app->view, x, y, app->map_data->ceiling_color);
		y++;
	}
	draw_texture_wall(app, ray, x);
	y = ray->draw_end;
	while (y <= app->view->win_height)
	{
		put_pixel_three_color(app->view, x, y, app->map_data->floor_color);
		y++;
	}
}