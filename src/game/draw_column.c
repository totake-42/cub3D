/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 17:00:00 by totake            #+#    #+#             */
/*   Updated: 2026/04/01 16:44:36 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"

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
 *
 * --- wall_x: exact hit position along the wall surface ---
 *
 * wall_x represents where exactly the ray hit the wall,
 * expressed as a value between 0.0 and 1.0.
 * It is used to determine which column of the texture to sample.
 *
 * --- Why WEST and SOUTH need to be flipped ---
 *
 * wall_x always increases in the direction of increasing coordinates
 * (Y increasing for vertical walls, X increasing for horizontal walls).
 *
 * However, when facing WEST or SOUTH, the player's left-to-right
 * view direction is opposite to the coordinate increase direction:
 *
 *   EAST  face: left=Y_small -> right=Y_large  (wall_x: 0->1)  matches
 *   WEST  face: left=Y_large -> right=Y_small  (wall_x: 0->1)  reversed
 *   NORTH face: left=X_small -> right=X_large  (wall_x: 0->1)  matches
 *   SOUTH face: left=X_large -> right=X_small  (wall_x: 0->1)  reversed
 *
 * Therefore, tex_x must be flipped for WEST (step_x < 0)
 * and SOUTH (step_y > 0).
 */
void	calc_draw_info(t_cub3d *app, t_ray_result *ray, t_draw_info *di,
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
	if (ray->side == 0 && ray->step_x < 0)
		di->tex_x = app->textures[tex_idx].width - di->tex_x - 1;
	if (ray->side == 1 && ray->step_y > 0)
		di->tex_x = app->textures[tex_idx].width - di->tex_x - 1;
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
void	draw_textured_column(t_cub3d *app, int x, t_draw_info *di, int tex_idx)
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
