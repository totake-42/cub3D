/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:00:00 by totake            #+#    #+#             */
/*   Updated: 2026/04/20 14:16:16 by totake           ###   ########.fr       */
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
	double	margin_x;
	double	margin_y;

	new_x = app->player.pos_x + app->player.dir_x * MOVE_SPEED;
	new_y = app->player.pos_y + app->player.dir_y * MOVE_SPEED;
	if (app->player.dir_x > 0)
		margin_x = new_x + COLLISION_MARGIN;
	else
		margin_x = new_x - COLLISION_MARGIN;
	if (app->player.dir_y > 0)
		margin_y = new_y + COLLISION_MARGIN;
	else
		margin_y = new_y - COLLISION_MARGIN;
	if (app->map_data->grid[(int)app->player.pos_y][(int)margin_x] != '1')
		app->player.pos_x = new_x;
	if (app->map_data->grid[(int)margin_y][(int)app->player.pos_x] != '1')
		app->player.pos_y = new_y;
}

/*
 * Move backward (S key)
 * Check collision before moving
 */
void	move_backward(t_cub3d *app)
{
	double	new_x;
	double	new_y;
	double	margin_x;
	double	margin_y;

	new_x = app->player.pos_x - app->player.dir_x * MOVE_SPEED;
	new_y = app->player.pos_y - app->player.dir_y * MOVE_SPEED;
	if (app->player.dir_x > 0)
		margin_x = new_x - COLLISION_MARGIN;
	else
		margin_x = new_x + COLLISION_MARGIN;
	if (app->player.dir_y > 0)
		margin_y = new_y - COLLISION_MARGIN;
	else
		margin_y = new_y + COLLISION_MARGIN;
	if (app->map_data->grid[(int)app->player.pos_y][(int)margin_x] != '1')
		app->player.pos_x = new_x;
	if (app->map_data->grid[(int)margin_y][(int)app->player.pos_x] != '1')
		app->player.pos_y = new_y;
}

/*
 * Move left (A key) - strafe left
 * Move perpendicular to the direction vector
 */
void	move_left(t_cub3d *app)
{
	double	new_x;
	double	new_y;
	double	margin_x;
	double	margin_y;

	new_x = app->player.pos_x + app->player.dir_y * MOVE_SPEED;
	new_y = app->player.pos_y - app->player.dir_x * MOVE_SPEED;
	if (app->player.dir_y > 0)
		margin_x = new_x + COLLISION_MARGIN;
	else
		margin_x = new_x - COLLISION_MARGIN;
	if (app->player.dir_x > 0)
		margin_y = new_y - COLLISION_MARGIN;
	else
		margin_y = new_y + COLLISION_MARGIN;
	if (app->map_data->grid[(int)app->player.pos_y][(int)margin_x] != '1')
		app->player.pos_x = new_x;
	if (app->map_data->grid[(int)margin_y][(int)app->player.pos_x] != '1')
		app->player.pos_y = new_y;
}

/*
 * Move right (D key) - strafe right
 * Move perpendicular to the direction vector
 */
void	move_right(t_cub3d *app)
{
	double	new_x;
	double	new_y;
	double	margin_x;
	double	margin_y;

	new_x = app->player.pos_x - app->player.dir_y * MOVE_SPEED;
	new_y = app->player.pos_y + app->player.dir_x * MOVE_SPEED;
	if (app->player.dir_y > 0)
		margin_x = new_x - COLLISION_MARGIN;
	else
		margin_x = new_x + COLLISION_MARGIN;
	if (app->player.dir_x > 0)
		margin_y = new_y + COLLISION_MARGIN;
	else
		margin_y = new_y - COLLISION_MARGIN;
	if (app->map_data->grid[(int)app->player.pos_y][(int)margin_x] != '1')
		app->player.pos_x = new_x;
	if (app->map_data->grid[(int)margin_y][(int)app->player.pos_x] != '1')
		app->player.pos_y = new_y;
}
