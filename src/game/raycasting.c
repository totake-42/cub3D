/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:00:00 by totake            #+#    #+#             */
/*   Updated: 2026/04/17 14:23:45 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"

/*
 * Cast a single ray and compute wall collision information.
 *
 * Performs the full raycasting pipeline for one ray:
 *   - Initialize DDA parameters
 *   - Detect wall collision using DDA
 *   - Compute perpendicular wall distance
 *   - Compute exact wall hit position for texture mapping
 *
 * Parameters:
 *   ray_x, ray_y → direction of the ray
 *
 * Returns:
 *   t_ray_result containing collision and rendering data.
 */

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
		r.perp_wall_dist = (dda.side_dist_x - dda.delta_dist_x);
	else
		r.perp_wall_dist = (dda.side_dist_y - dda.delta_dist_y);
	if (r.side == 0)
		r.wall_x = app->player.pos_y + r.perp_wall_dist * ray_y;
	else
		r.wall_x = app->player.pos_x + r.perp_wall_dist * ray_x;
	r.wall_x -= floor(r.wall_x);
	return (r);
}

/*
 * Select the wall texture based on ray collision direction.
 *
 * Determines which texture should be used depending on:
 *   - which side of the grid cell was hit
 *   - the direction the ray was traveling
 *
 * ray->side:
 *   0 → vertical wall hit (EAST/WEST wall)
 *   1 → horizontal wall hit (NORTH/SOUTH wall)
 *
 * ray->step_x / ray->step_y:
 *   indicate the ray movement direction:
 *     negative → ray moving toward WEST or NORTH
 *     positive → ray moving toward EAST or SOUTH
 *
 * Returns:
 *   Texture index corresponding to wall orientation.
 */

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

/*
 * Render the 3D scene using raycasting.
 *
 * For each vertical screen column:
 *   1. Compute the ray direction from the camera.
 *   2. Cast a ray into the map to find the wall hit.
 *   3. Select the correct wall texture.
 *   4. Compute drawing parameters for the wall slice.
 *   5. Draw the textured vertical column.
 *
 * camera_x:
 *   Normalized horizontal camera coordinate in range [-1, 1].
 *   -1 corresponds to the left edge of the screen,
 *    0 corresponds to the center of the view,
 *   +1 corresponds to the right edge.
 *   This value represents where the current column lies
 *   inside the player's field of view.
 *
 * ray_dir:
 *   Direction vector of the ray cast for the current column.
 *   It is computed by combining:
 *     - the player's forward direction (dir)
 *     - the camera plane vector (plane) scaled by camera_x
 *
 *       ray_dir = player_dir + camera_plane * camera_x
 *
 *   The camera plane represents the width of the field of view,
 *   so changing camera_x rotates the ray across the screen,
 *   producing different viewing angles for each column.
 *
 * The scene is rendered column by column from left to right.
 * A 3D view is created by drawing many vertical wall slices
 * side by side, giving the illusion of a 3D world.
 */

/*
 * --- Understanding ray_dir using player_dir = (0, -1) ---
 *
 * Ray direction formula:
 *
 *     ray_dir = player_dir + camera_plane * camera_x
 *
 * where:
 *     player_dir   -> direction the player is facing
 *     camera_plane -> perpendicular vector defining screen width (FOV)
 *     camera_x     -> horizontal screen coordinate in range [-1, 1]
 *
 *
 * Example setup:
 * -------------------------------------------------------
 *
 *     player_dir   = (0, -1)      // looking toward negative Y (north)
 *     camera_plane = (0.66, 0)    // perpendicular to player_dir
 *
 * The camera plane spreads rays horizontally.
 *
 *
 * -------------------------------------------------------
 * 1) camera_x = -1   (LEFT side of the screen)
 *
 *     ray_dir =
 *         (0, -1)
 *       + (0.66, 0) * (-1)
 *       = (-0.66, -1)
 *
 * → Ray goes forward-left.
 *
 *
 * -------------------------------------------------------
 * 2) camera_x = 0    (CENTER of the screen)
 *
 *     ray_dir =
 *         (0, -1)
 *       + (0.66, 0) * (0)
 *       = (0, -1)
 *
 * → Ray goes straight forward.
 *
 *
 * -------------------------------------------------------
 * 3) camera_x = 0.5  (RIGHT side of the screen)
 *
 *     ray_dir =
 *         (0, -1)
 *       + (0.66, 0) * (0.5)
 *       = (0.33, -1)
 *
 * → Ray goes forward-right.
 *
 *
 * Conceptual view (top-down):
 *
 *          left ray      center ray      right ray
 *              \            |            /
 *               \           |           /
 *                \          |          /
 *                 \         |         /
 *                    Player (looking up)
 *
 * Each vertical screen column corresponds to a different camera_x.
 * By casting many rays from left to right, the engine reconstructs
 * a pseudo-3D image using vertical wall slices.
 */

void	raycast_all(t_cub3d *app)
{
	int				x;
	double			camera_x;
	t_ray_result	ray;
	int				tex_idx;
	t_draw_info		di;

	x = 0;
	while (x < app->view->win_width)
	{
		camera_x = 2.0 * x / (double)app->view->win_width - 1.0;
		ray = cast_single_ray(app, app->player.dir_x + app->player.plane_x
				* camera_x, app->player.dir_y + app->player.plane_y * camera_x);
		tex_idx = select_texture(&ray);
		calc_draw_info(app, &ray, &di, tex_idx);
		draw_textured_column(app, x, &di, tex_idx);
		x++;
	}
}
