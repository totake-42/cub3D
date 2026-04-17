/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:20:00 by totake            #+#    #+#             */
/*   Updated: 2026/04/17 14:20:02 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

/*
 * Set the player's direction and camera plane based on the character
 * N: North (dir: up, 0, -1)
 * S: South (dir: down, 0, 1)
 * E: East  (dir: right, 1, 0)
 * W: West  (dir: left, -1, 0)
 */
// static void	set_player_direction(t_player *player, char direction)
// {
// 	if (direction == 'N')
// 	{
// 		player->dir_x = 0.0;
// 		player->dir_y = -1.0;
// 		player->plane_x = 0.66;
// 		player->plane_y = 0.0;
// 	}
// 	else if (direction == 'S')
// 	{
// 		player->dir_x = 0.0;
// 		player->dir_y = 1.0;
// 		player->plane_x = -0.66;
// 		player->plane_y = 0.0;
// 	}
// 	else if (direction == 'E')
// 	{
// 		player->dir_x = 1.0;
// 		player->dir_y = 0.0;
// 		player->plane_x = 0.0;
// 		player->plane_y = 0.66;
// 	}
// 	else if (direction == 'W')
// 	{
// 		player->dir_x = -1.0;
// 		player->dir_y = 0.0;
// 		player->plane_x = 0.0;
// 		player->plane_y = -0.66;
// 	}
// }

static void	set_player_direction(t_player *player, char direction)
{
	if (direction == 'N')
	{
		player->dir_x = 0.0;
		player->dir_y = -1.0;
		player->plane_x = 0.66;
		player->plane_y = 0.0;
	}
	else if (direction == 'S')
	{
		player->dir_x = 0.0;
		player->dir_y = 1.0;
		player->plane_x = -0.66;
		player->plane_y = 0.0;
	}
	else if (direction == 'E')
	{
		player->dir_x = 1.0;
		player->dir_y = 0.0;
		player->plane_x = 0.0;
		player->plane_y = 0.66;
	}
	else if (direction == 'W')
	{
		player->dir_x = -1.0;
		player->dir_y = 0.0;
		player->plane_x = 0.0;
		player->plane_y = -0.66;
	}
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
	direction = app->map_data->grid[app->map_data->player_y][app->map_data->player_x];
	set_player_direction(&app->player, direction);
}
