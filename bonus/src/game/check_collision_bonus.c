/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:11:37 by totake            #+#    #+#             */
/*   Updated: 2026/04/22 13:14:04 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "game_bonus.h"

/*
 * Check if a single point is inside a wall or out of bounds
 * Returns: 1 if collision, 0 if safe
 */
static int	is_wall_at(t_cub3d *app, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_y < 0
		|| map_y >= app->map_data->grid_height
		|| map_x >= app->map_data->grid_width
		|| app->map_data->grid[map_y][map_x] == '1')
		return (1);
	return (0);
}

/*
 * AABB collision detection - Four corners check
 * Check only the 4 corners of the player's bounding box
 * More efficient than checking all tiles in the AABB
 * Returns: 1 if collision detected, 0 if safe to move
 */
int	check_collision(t_cub3d *app, double new_x, double new_y)
{
	if (is_wall_at(app, new_x - PLAYER_RADIUS, new_y - PLAYER_RADIUS))
		return (1);
	if (is_wall_at(app, new_x + PLAYER_RADIUS, new_y - PLAYER_RADIUS))
		return (1);
	if (is_wall_at(app, new_x - PLAYER_RADIUS, new_y + PLAYER_RADIUS))
		return (1);
	if (is_wall_at(app, new_x + PLAYER_RADIUS, new_y + PLAYER_RADIUS))
		return (1);
	return (0);
}
