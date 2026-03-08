/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 19:05:17 by tigarashi         #+#    #+#             */
/*   Updated: 2026/03/08 22:03:41 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

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


#include <stdio.h>
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


void	drawline(t_cub3d *app, t_ray *ray, int x)
{
	int		y;

	y = 0;
	while (y < ray->draw_start)
	{
		put_pixel_three_color(app->view, x, y, app->map_data->ceiling_color);
		y++;
	}
	while (y <= ray->draw_end)
	{
		put_pixel(app->view, x, y, ray->wall_color);
        y++;
	}
	while (y <= app->view->win_height)
	{
		put_pixel_three_color(app->view, x, y, app->map_data->floor_color);
		y++;
	}
}