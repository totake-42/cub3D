/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 22:46:54 by tigarashi         #+#    #+#             */
/*   Updated: 2026/03/12 00:04:52 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d.h"
#include "render.h"

static void	draw_minimap(t_cub3d *app, int y);

void	render_minimap(t_cub3d *app)
{
	int	y;
	int	map_end;

	y = app->minimap.offset_height;
	map_end = app->minimap.height + app->minimap.offset_height;
	while (y < map_end)
	{
		draw_minimap(app, y);
		y++;
	}
	// playerの位置を描画する。
	y = app->minimap.map_center_y - 5;
	while (y <= app->minimap.map_center_y + 5)
	{
		int x = app->minimap.map_center_x - 5;
		while (x <= app->minimap.map_center_x + 5)
		{
			put_pixel(app->view, x, y, MINIMAP_PLAYER_COLOR);
			x++;
		}
		y++;
	}
}

static void	draw_minimap(t_cub3d *app, int y)
{
	double	dx;
	double	dy;
	double	world_dx;
	double	world_dy;
	double	map_x;
	double	map_y;
	int		x;
	int		map_end;
	
	x = app->minimap.offset_width;
	map_end = app->minimap.width + app->minimap.offset_width;
	while (x < map_end)
	{
		// ミニマップの中心からのプレイヤーの位置を探す。
		dx = x - app->minimap.map_center_x;
		dy = y - app->minimap.map_center_y;

		// それをgridの座標系に変換する
		world_dx = dx / app->minimap.tile_size;
		world_dy = dy / app->minimap.tile_size;

		// grid座標系でのプレイヤーの現在地を足す。
		map_x = app->player.pos_x + world_dx;
		map_y = app->player.pos_y + world_dy;

		if (is_inmap(map_x, map_y, app->map_data) == false)
		{
			x++;
			continue ;
		}
		if (app->map_data->grid[(int)map_y][(int)map_x] == '1')
			put_pixel(app->view, x, y, MINIMAP_WALL_COLOR);
		else
			put_pixel_three_color(app->view, x, y, app->map_data->floor_color);
		x++;
	}
}