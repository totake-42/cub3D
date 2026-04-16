/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 17:00:00 by totake            #+#    #+#             */
/*   Updated: 2026/04/12 22:19:28 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"

/*
 * Initialize DDA (Digital Differential Analyzer) parameters
 *
 * 1. Determine the current grid cell
 *    The player's position is a floating point value,
 *    but the map is a grid of integer cells.
 *    example:
 *      pos_x = 3.5 → map_x = 3
 *      pos_y = 2.7 → map_y = 2
 *
 * 2. Calculate delta_dist_x / delta_dist_y
 *    These represent the distance the ray must travel
 *    to move from one grid line to the next.
 *
 *    They are computed as the absolute inverse of the ray direction:
 *      delta_dist_x = fabs(1 / ray_x)
 *      delta_dist_y = fabs(1 / ray_y)
 *
 *    example:
 *      ray_x = 0.5 → delta_dist_x = fabs(1 / 0.5) = 2.0
 *      (1 step moves only 0.5 in X, so 2 steps needed to cross one grid line)
 *
 * 3. Determine step_x / step_y
 *    These indicate the direction in which the ray will step:
 *      ray_x < 0 → step_x = -1 (left)
 *      ray_x > 0 → step_x = +1 (right)
 *      ray_y < 0 → step_y = -1 (up)
 *      ray_y > 0 → step_y = +1 (down)
 *
 * 4. Calculate side_dist_x / side_dist_y
 *    These represent the distance from the player's position
 *    to the first grid boundary in each direction.
 *
 *    If stepping in the negative direction:
 *      side_dist_x = (pos_x - map_x) * delta_dist_x
 *      side_dist_y = (pos_y - map_y) * delta_dist_y
 *
 *    If stepping in the positive direction:
 *      side_dist_x = (map_x + 1.0 - pos_x) * delta_dist_x
 *      side_dist_y = (map_y + 1.0 - pos_y) * delta_dist_y
 *
 *    example:
 *      pos_y = 2.7, map_y = 2, ray_y = -1 (moving upward)
 *      → side_dist_y = (2.7 - 2) * 1.0 = 0.7
 *
 * After this initialization, the DDA loop can repeatedly compare
 * side_dist_x and side_dist_y to determine which grid boundary
 * the ray will hit next.
 */
void	init_dda(t_dda *dda, t_player *p, double ray_x, double ray_y)
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

/*
 * Perform DDA (Digital Differential Analyzer) to find wall collision
 *
 * The ray moves step-by-step through the grid (map),
 * choosing the next closest grid boundary (X or Y).
 *
 * dda->side_dist_x: Distance to next vertical grid line (X side)
 * dda->side_dist_y: Distance to next horizontal grid line (Y side)
 *
 * At each step:
 *  - Compare side_dist_x and side_dist_y
 *  - Move in the direction of the smaller one (closer boundary)
 *
 * If side_dist_x < side_dist_y:
 *   → The ray hits a vertical side first (moving in X direction)
 *   → map_x += step_x
 *   → side = 0 (X side)
 *
 * Else:
 *   → The ray hits a horizontal side first (moving in Y direction)
 *   → map_y += step_y
 *   → side = 1 (Y side)
 *
 * After moving:
 *   - Check if the ray is outside the map → stop
 *   - Check if current cell is a wall ('1') → stop
 *
 * Return value:
 *   side = 0 → hit vertical wall (X side)
 *   side = 1 → hit horizontal wall (Y side)
 */
int	run_dda(t_dda *dda, t_map *map)
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
