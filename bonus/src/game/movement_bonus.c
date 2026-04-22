/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:08:28 by totake            #+#    #+#             */
/*   Updated: 2026/04/21 14:08:31 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "game_bonus.h"

/*
 * Move forward (W key)
 * Check collision using AABB (4 corners) before moving
 * X and Y axes are checked separately for wall sliding
 */
void	move_forward(t_cub3d *app)
{
	double	new_x;
	double	new_y;

	new_x = app->player.pos_x + app->player.dir_x * MOVE_SPEED;
	new_y = app->player.pos_y + app->player.dir_y * MOVE_SPEED;
	if (!check_collision(app, new_x, app->player.pos_y))
		app->player.pos_x = new_x;
	if (!check_collision(app, app->player.pos_x, new_y))
		app->player.pos_y = new_y;
}

/*
 * Move backward (S key)
 * Check collision using AABB (4 corners) before moving
 * X and Y axes are checked separately for wall sliding
 */
void	move_backward(t_cub3d *app)
{
	double	new_x;
	double	new_y;

	new_x = app->player.pos_x - app->player.dir_x * MOVE_SPEED;
	new_y = app->player.pos_y - app->player.dir_y * MOVE_SPEED;
	if (!check_collision(app, new_x, app->player.pos_y))
		app->player.pos_x = new_x;
	if (!check_collision(app, app->player.pos_x, new_y))
		app->player.pos_y = new_y;
}

/*
 * Move left (A key) - strafe left
 * Strafe left perpendicular to the direction vector
 * Check collision using AABB (4 corners) before moving
 */
void	move_left(t_cub3d *app)
{
	double	new_x;
	double	new_y;

	new_x = app->player.pos_x + app->player.dir_y * MOVE_SPEED;
	new_y = app->player.pos_y - app->player.dir_x * MOVE_SPEED;
	if (!check_collision(app, new_x, app->player.pos_y))
		app->player.pos_x = new_x;
	if (!check_collision(app, app->player.pos_x, new_y))
		app->player.pos_y = new_y;
}

/*
 * Move right (D key) - strafe right
 * Strafe right perpendicular to the direction vector
 * Check collision using AABB (4 corners) before moving
 */
void	move_right(t_cub3d *app)
{
	double	new_x;
	double	new_y;

	new_x = app->player.pos_x - app->player.dir_y * MOVE_SPEED;
	new_y = app->player.pos_y + app->player.dir_x * MOVE_SPEED;
	if (!check_collision(app, new_x, app->player.pos_y))
		app->player.pos_x = new_x;
	if (!check_collision(app, app->player.pos_x, new_y))
		app->player.pos_y = new_y;
}
