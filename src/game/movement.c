/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:00:00 by totake            #+#    #+#             */
/*   Updated: 2026/02/21 16:43:29 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"

/*
 * Move forward (W key)
 * Check collision before moving
 */
void	move_forward(t_cub3d *app)
{
	double	new_x;
	double	new_y;

	new_x = app->player.pos_x + app->player.dir_x * MOVE_SPEED;
	new_y = app->player.pos_y + app->player.dir_y * MOVE_SPEED;
	if (app->map_data->grid[(int)new_y][(int)new_x] != '1')
	{
		app->player.pos_x = new_x;
		app->player.pos_y = new_y;
	}
}

/*
 * Move backward (S key)
 * Check collision before moving
 */
void	move_backward(t_cub3d *app)
{
	double	new_x;
	double	new_y;

	new_x = app->player.pos_x - app->player.dir_x * MOVE_SPEED;
	new_y = app->player.pos_y - app->player.dir_y * MOVE_SPEED;
	if (app->map_data->grid[(int)new_y][(int)new_x] != '1')
	{
		app->player.pos_x = new_x;
		app->player.pos_y = new_y;
	}
}

/*
 * Move left (A key) - strafe left
 * Move perpendicular to the direction vector
 */
void	move_left(t_cub3d *app)
{
	double	new_x;
	double	new_y;

	new_x = app->player.pos_x - app->player.dir_y * MOVE_SPEED;
	new_y = app->player.pos_y + app->player.dir_x * MOVE_SPEED;
	if (app->map_data->grid[(int)new_y][(int)new_x] != '1')
	{
		app->player.pos_x = new_x;
		app->player.pos_y = new_y;
	}
}

/*
 * Move right (D key) - strafe right
 * Move perpendicular to the direction vector
 */
void	move_right(t_cub3d *app)
{
	double	new_x;
	double	new_y;

	new_x = app->player.pos_x + app->player.dir_y * MOVE_SPEED;
	new_y = app->player.pos_y - app->player.dir_x * MOVE_SPEED;
	if (app->map_data->grid[(int)new_y][(int)new_x] != '1')
	{
		app->player.pos_x = new_x;
		app->player.pos_y = new_y;
	}
}

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
