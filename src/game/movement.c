/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:00:00 by totake            #+#    #+#             */
/*   Updated: 2026/04/01 17:43:56 by totake           ###   ########.fr       */
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

	new_x = app->player.pos_x + app->player.dir_y * MOVE_SPEED;
	new_y = app->player.pos_y - app->player.dir_x * MOVE_SPEED;
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

	new_x = app->player.pos_x - app->player.dir_y * MOVE_SPEED;
	new_y = app->player.pos_y + app->player.dir_x * MOVE_SPEED;
	if (app->map_data->grid[(int)new_y][(int)new_x] != '1')
	{
		app->player.pos_x = new_x;
		app->player.pos_y = new_y;
	}
}
