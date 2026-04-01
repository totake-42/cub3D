/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 17:43:20 by totake            #+#    #+#             */
/*   Updated: 2026/04/01 17:43:33 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"

/*
 * Rotate right (Right arrow key)
 * Rotate both direction vector and camera plane
 */
void	rotate_right(t_cub3d *app)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = app->player.dir_x;
	app->player.dir_x = old_dir_x * cos(ROT_SPEED) - app->player.dir_y
		* sin(ROT_SPEED);
	app->player.dir_y = old_dir_x * sin(ROT_SPEED) + app->player.dir_y
		* cos(ROT_SPEED);
	old_plane_x = app->player.plane_x;
	app->player.plane_x = old_plane_x * cos(ROT_SPEED) - app->player.plane_y
		* sin(ROT_SPEED);
	app->player.plane_y = old_plane_x * sin(ROT_SPEED) + app->player.plane_y
		* cos(ROT_SPEED);
}

/*
 * Rotate left (Left arrow key)
 * Rotate both direction vector and camera plane
 */
void	rotate_left(t_cub3d *app)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = app->player.dir_x;
	app->player.dir_x = old_dir_x * cos(-ROT_SPEED) - app->player.dir_y
		* sin(-ROT_SPEED);
	app->player.dir_y = old_dir_x * sin(-ROT_SPEED) + app->player.dir_y
		* cos(-ROT_SPEED);
	old_plane_x = app->player.plane_x;
	app->player.plane_x = old_plane_x * cos(-ROT_SPEED) - app->player.plane_y
		* sin(-ROT_SPEED);
	app->player.plane_y = old_plane_x * sin(-ROT_SPEED) + app->player.plane_y
		* cos(-ROT_SPEED);
}
