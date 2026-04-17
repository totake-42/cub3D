/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:20:00 by totake            #+#    #+#             */
/*   Updated: 2026/04/17 14:49:16 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static void	set_direction_north(t_player *player)
{
	player->dir_x = 0.0;
	player->dir_y = -1.0;
	player->plane_x = 0.66;
	player->plane_y = 0.0;
}

static void	set_direction_south(t_player *player)
{
	player->dir_x = 0.0;
	player->dir_y = 1.0;
	player->plane_x = -0.66;
	player->plane_y = 0.0;
}

static void	set_direction_east(t_player *player)
{
	player->dir_x = 1.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.66;
}

static void	set_direction_west(t_player *player)
{
	player->dir_x = -1.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = -0.66;
}

/*
 * Initialize the player based on the map data
 * Sets the player's position, direction, and camera plane
 * app->map_data->player_x = 3; X cordinate of the player in the map grid
 * app->map_data->player_y = 2; Y cordinate of the player in the map grid
 * app->map_data->grid[2][3] = 'N';
 * app->player.pos_x = 3.5; Player's X position in the center of the cell
 * app->player.pos_y = 2.5; Player's Y position in the center of the cell
 */
void	init_player(t_cub3d *app)
{
	char	direction;

	app->player.pos_x = (double)app->map_data->player_x + 0.5;
	app->player.pos_y = (double)app->map_data->player_y + 0.5;
	direction = app->map_data->grid[app->map_data->player_y] \
		[app->map_data->player_x];
	if (direction == 'N')
		set_direction_north(&app->player);
	else if (direction == 'S')
		set_direction_south(&app->player);
	else if (direction == 'E')
		set_direction_east(&app->player);
	else if (direction == 'W')
		set_direction_west(&app->player);
}
