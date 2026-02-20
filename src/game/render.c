/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:00:00 by itakumi           #+#    #+#             */
/*   Updated: 2026/02/20 14:13:36 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * fill the pixel at (x, y) with the specified color
 * This function assumes that the color is in 0xRRGGBB format.
 */
static void	put_pixel(t_minilibx *view, int x, int y, int color)
{
	char	*dst;
	int		offset;

	if (x < 0 || x >= view->win_width || y < 0 || y >= view->win_height)
		return ;
	offset = y * view->size_line + x * (view->bits_per_pixel / 8);
	dst = view->data_addr + offset;
	if (view->endian == 0)
	{
		dst[0] = (color)&0xFF;
		dst[1] = (color >> 8) & 0xFF;
		dst[2] = (color >> 16) & 0xFF;
		dst[3] = 0;
	}
	else
	{
		dst[0] = (color >> 16) & 0xFF;
		dst[1] = (color >> 8) & 0xFF;
		dst[2] = (color)&0xFF;
		dst[3] = 0;
	}
}

// /**
//  * fill the entire screen with the specified color
//  */
// static void	fill_screen(t_minilibx *view, int color)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < view->win_height)
// 	{
// 		x = 0;
// 		while (x < view->win_width)
// 		{
// 			put_pixel(view, x, y, color);
// 			x++;
// 		}
// 		y++;
// 	}
// }

/**
 * render the ceiling and floor

	* the ceiling is filled with the ceiling color and the floor is filled with the floor color
 */
void	render(t_cub3d *app)
{
	int	ceiling_color;
	int	floor_color;
	int	mid_y;
	int	x;
	int	y;

	ceiling_color = (app->map_data->ceiling_color[0] << 16) | (app->map_data->ceiling_color[1] << 8) | app->map_data->ceiling_color[2];
	floor_color = (app->map_data->floor_color[0] << 16) | (app->map_data->floor_color[1] << 8) | app->map_data->floor_color[2];
	mid_y = app->view->win_height / 2;
	y = 0;
	while (y < mid_y)
	{
		x = 0;
		while (x < app->view->win_width)
		{
			put_pixel(app->view, x, y, ceiling_color);
			x++;
		}
		y++;
	}
	while (y < app->view->win_height)
	{
		x = 0;
		while (x < app->view->win_width)
		{
			put_pixel(app->view, x, y, floor_color);
			x++;
		}
		y++;
	}
}
