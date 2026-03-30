/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:00:00 by totake            #+#    #+#             */
/*   Updated: 2026/03/28 19:09:20 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_dda
{
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	int				step_x;
	int				step_y;
}					t_dda;

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
 *      ray_y = -1 → delta_dist_y = 1.0
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
static void	init_dda(t_dda *dda, t_player *p, double ray_x, double ray_y)
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

static int	run_dda(t_dda *dda, t_map *map)
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
		r.perp_wall_dist = (dda.map_x - app->player.pos_x + (1 - dda.step_x)
				/ 2) / ray_x;
	else
		r.perp_wall_dist = (dda.map_y - app->player.pos_y + (1 - dda.step_y)
				/ 2) / ray_y;
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
 * Calculate vertical drawing range of the wall slice.
 *
 * - draw_start : top Y coordinate of the wall
 * - draw_end   : bottom Y coordinate of the wall
 *
 * line_height is computed as:
 *     line_height = win_height / perp_wall_dist;
 *
 * When perp_wall_dist is smaller than 1.0 (i.e. the wall is very
 * close to the camera), line_height can exceed the window height.
 * In this case, the projected wall extends beyond the screen and
 * draw_start may become negative.
 *
 * To prevent drawing outside the screen buffer, draw_start is
 * clamped to 0.
 */

static void	calc_draw_info(t_cub3d *app, t_ray_result *ray, t_draw_info *di,
		int tex_idx)
{
	di->line_height = (int)(app->view->win_height / ray->perp_wall_dist);
	di->draw_start = -di->line_height / 2 + app->view->win_height / 2;
	if (di->draw_start < 0)
		di->draw_start = 0;
	di->draw_end = di->line_height / 2 + app->view->win_height / 2;
	if (di->draw_end >= app->view->win_height)
		di->draw_end = app->view->win_height - 1;
	di->tex_x = (int)(ray->wall_x * app->textures[tex_idx].width);
	// if (ray->side == 0 && ray->step_x > 0)
	// 	di->tex_x = app->textures[tex_idx].width - di->tex_x - 1;
	// if (ray->side == 1 && ray->step_y < 0)
	// 	di->tex_x = app->textures[tex_idx].width - di->tex_x - 1;
}

/*
 * Returns the color value at (tex_x, tex_y) from the texture image.
 * Converts 2D texture coordinates into a memory address and reads
 * the pixel color directly from the image buffer.
 */

static int	get_tex_color(t_texture *tex, int tex_x, int tex_y)
{
	char	*src;

	src = tex->data_addr + (tex_y * tex->size_line + tex_x
			* (tex->bits_per_pixel / 8));
	return (*(int *)src);
}

/*
 * Draw a textured vertical wall slice at column x.
 *
 * step:
 *   Amount the texture moves vertically for each screen pixel.
 *   This scales the texture to match the projected wall height.
 *
 * tex_pos:
 *   Current floating-point position inside the texture.
 *   It starts at the texture location corresponding to draw_start
 *   and increases by 'step' for every pixel drawn.
 *
 * tex_y:
 *   Integer Y coordinate in the texture derived from tex_pos.
 *   The value is clamped to the valid texture range
 *   [0, texture_height - 1] to prevent out-of-bounds access.
 */

static void	draw_textured_column(t_cub3d *app, int x, t_draw_info *di,
		int tex_idx)
{
	int		y;
	int		tex_y;
	double	step;
	double	tex_pos;
	char	*dst;

	step = 1.0 * app->textures[tex_idx].height / di->line_height;
	tex_pos = (di->draw_start - app->view->win_height / 2 + di->line_height / 2)
		* step;
	y = di->draw_start;
	while (y <= di->draw_end)
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		else if (tex_y >= app->textures[tex_idx].height)
			tex_y = app->textures[tex_idx].height - 1;
		tex_pos += step;
		dst = app->view->data_addr + (y * app->view->size_line + x
				* (app->view->bits_per_pixel / 8));
		*(int *)dst = get_tex_color(&app->textures[tex_idx], di->tex_x, tex_y);
		y++;
	}
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
	double			ray_dir[2];
	t_ray_result	ray;
	int				tex_idx;
	t_draw_info		di;

	x = 0;
	while (x < app->view->win_width)
	{
		camera_x = 2.0 * x / (double)app->view->win_width - 1.0;
		ray_dir[0] = app->player.dir_x + app->player.plane_x * camera_x;
		ray_dir[1] = app->player.dir_y + app->player.plane_y * camera_x;
		ray = cast_single_ray(app, ray_dir[0], ray_dir[1]);
		tex_idx = select_texture(&ray);
		calc_draw_info(app, &ray, &di, tex_idx);
		draw_textured_column(app, x, &di, tex_idx);
		x++;
	}
}

void	raycast_single(t_cub3d *app)
{
	t_ray_result	ray;
	static int		frame_count = 0;

	ray = cast_single_ray(app, app->player.dir_x, app->player.dir_y);
	if (frame_count < 5)
	{
		printf("Distance: %.2f, Side: %d\n", ray.perp_wall_dist, ray.side);
		frame_count++;
	}
}
