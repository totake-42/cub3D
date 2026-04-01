/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:00:00 by itakumi           #+#    #+#             */
/*   Updated: 2026/04/01 17:41:59 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"

/*
 * Write a single pixel into the image buffer at position (x, y).
 *
 * The image buffer is a flat array of bytes (data_addr).
 * Each pixel occupies (bits_per_pixel / 8) bytes.
 * The byte offset for pixel (x, y) is:
 *   offset = y * size_line + x * (bits_per_pixel / 8)
 *
 * Color format: 0xTTRRGGBB (TRGB, 32-bit)
 *   All 4 bytes (T, R, G, B) are written directly into the image buffer.
 *
 * Byte order depends on endianness:
 *   endian == 0 (little-endian): stored as B, G, R, T
 *   endian == 1 (big-endian):    stored as R, G, B, T
 *
 * Bounds check: pixels outside the window are silently ignored.
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
		dst[0] = (color) & 0xFF;
		dst[1] = (color >> 8) & 0xFF;
		dst[2] = (color >> 16) & 0xFF;
		dst[3] = (color >> 24) & 0xFF;
	}
	else
	{
		dst[0] = (color >> 16) & 0xFF;
		dst[1] = (color >> 8) & 0xFF;
		dst[2] = (color) & 0xFF;
		dst[3] = (color >> 24) & 0xFF;
	}
}

/*
 * Render one complete frame to the image buffer.
 *
 * This function is called every frame from game_loop().
 * It draws the scene in three steps:
 *
 * Step 1 - Ceiling (top half of the screen):
 *   Fill every pixel from y=0 to y=mid_y with ceiling_color.
 *
 * Step 2 - Floor (bottom half of the screen):
 *   Fill every pixel from y=mid_y to y=win_height with floor_color.
 *
 * Step 3 - Walls (raycasting):
 *   Call raycast_all() to cast one ray per screen column.
 *   Each ray computes the wall distance and draws a textured
 *   vertical slice on top of the ceiling/floor background.
 *
 * Color conversion:
 *   The map stores colors as RGB arrays [R, G, B].
 *   They are packed into a single int as 0xRRGGBB:
 *     color = (R << 16) | (G << 8) | B
 *
 * Screen layout after rendering:
 *   y=0       ┌──────────────┐
 *             │   ceiling    │
 *   y=mid_y   ├──┬────────┬──┤
 *             │  │  wall  │  │  <- drawn by raycast_all()
 *   y=win_h   ├──┴────────┴──┤
 *             │   floor      │
 *             └──────────────┘
 */
static void	fill_background(t_cub3d *app, int ceiling_color, int floor_color)
{
	int	mid_y;
	int	x;
	int	y;

	mid_y = app->view->win_height / 2;
	y = 0;
	while (y < mid_y)
	{
		x = 0;
		while (x < app->view->win_width)
			put_pixel(app->view, x++, y, ceiling_color);
		y++;
	}
	while (y < app->view->win_height)
	{
		x = 0;
		while (x < app->view->win_width)
			put_pixel(app->view, x++, y, floor_color);
		y++;
	}
}

void	render(t_cub3d *app)
{
	int	ceiling_color;
	int	floor_color;

	ceiling_color = (app->map_data->ceiling_color[0] << 16)
		| (app->map_data->ceiling_color[1] << 8)
		| app->map_data->ceiling_color[2];
	floor_color = (app->map_data->floor_color[0] << 16)
		| (app->map_data->floor_color[1] << 8)
		| app->map_data->floor_color[2];
	fill_background(app, ceiling_color, floor_color);
	raycast_all(app);
}
