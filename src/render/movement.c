/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 16:54:14 by tigarashi         #+#    #+#             */
/*   Updated: 2026/03/11 20:34:57 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx.h"
#include <stdlib.h>

#include "cub3d.h"
#include "render.h"
#include "utils.h"

void	move_forward(t_cub3d *app)
{
	double	frametime;
	double	move_speed;
	double	oldtime;

	oldtime = app->time;
	app->time = get_time();
	frametime = app->time - oldtime;
	move_speed = frametime * MOVE_SPEED;
	if (app->map_data->grid[(int)app->player.pos_y][(int)(app->player.pos_x + app->player.dir_x * move_speed)] != '1')
		app->player.pos_x = app->player.pos_x + app->player.dir_x * move_speed;
	if (app->map_data->grid[(int)(app->player.pos_y + app->player.dir_y * move_speed)][(int)(app->player.pos_x)] != '1')
		app->player.pos_y = app->player.pos_y + app->player.dir_y * move_speed; 
}

void	move_backward(t_cub3d *app)
{
	double	frametime;
	double	move_speed;
	double	oldtime;

	oldtime = app->time;
	app->time = get_time();
	frametime = app->time - oldtime;
	move_speed = frametime * MOVE_SPEED;
	if (app->map_data->grid[(int)app->player.pos_y][(int)(app->player.pos_x - app->player.dir_x * move_speed)] != '1')
		app->player.pos_x = app->player.pos_x - app->player.dir_x * move_speed;
	if (app->map_data->grid[(int)(app->player.pos_y - app->player.dir_y * move_speed)][(int)(app->player.pos_x)] != '1')
		app->player.pos_y = app->player.pos_y - app->player.dir_y * move_speed; 
}

void	move_left(t_cub3d *app)
{
	double	frametime;
	double	move_speed;
	double	oldtime;

	oldtime = app->time;
	app->time = get_time();
	frametime = app->time - oldtime;
	move_speed = frametime * MOVE_SPEED; 
	// dir の直交ベクトルを計算する（dirの90度回転) 
	if (app->map_data->grid[(int)(app->player.pos_y)][(int)(app->player.pos_x - app->player.dir_y * move_speed)] != '1')
		app->player.pos_x = app->player.pos_x - app->player.dir_y * move_speed;
	if (app->map_data->grid[(int)(app->player.pos_y + app->player.dir_x * move_speed)][(int)(app->player.pos_x)] != '1')
		app->player.pos_y = app->player.pos_y + app->player.dir_x * move_speed;
}

void	move_right(t_cub3d *app)
{
	double	frametime;
	double	move_speed;
	double	oldtime;

	oldtime = app->time;
	app->time = get_time();
	frametime = app->time - oldtime;
	move_speed = frametime * MOVE_SPEED; 
	// dir の直交ベクトルを計算する（dirの-90度回転) 
	if (app->map_data->grid[(int)(app->player.pos_y)][(int)(app->player.pos_x + app->player.dir_y * move_speed)] != '1')
		app->player.pos_x = app->player.pos_x + app->player.dir_y * move_speed;
	if (app->map_data->grid[(int)(app->player.pos_y - app->player.dir_x * move_speed)][(int)(app->player.pos_x)] != '1')
		app->player.pos_y = app->player.pos_y - app->player.dir_x * move_speed;
}



void	rotate_left(t_cub3d *app)
{
	double	oldtime;
	double	frametime;
	double	rotate_speed;
	double	old_dir_x;
	double	old_plane_x;

	oldtime = app->time;
	app->time = get_time();
	if (app->time == -1)
		exit_cub3d(app, EXIT_FAILURE);
	frametime = app->time - oldtime;
	rotate_speed = frametime * ROTATE_SPEED; 
	old_dir_x = app->player.dir_x;
	app->player.dir_x = old_dir_x * cos(rotate_speed) - app->player.dir_y * sin(rotate_speed);
	app->player.dir_y = old_dir_x * sin(rotate_speed) + app->player.dir_y * cos(rotate_speed);
	old_plane_x = app->player.plane_x;
	app->player.plane_x = old_plane_x * cos(rotate_speed) - app->player.plane_y * sin(rotate_speed);
	app->player.plane_y = old_plane_x * sin(rotate_speed) + app->player.plane_y * cos(rotate_speed);
}

void	rotate_right(t_cub3d *app)
{
	double	oldtime;
	double	frametime;
	double	rotate_speed;
	double	old_dir_x;
	double	old_plane_x;

	oldtime = app->time;
	app->time = get_time();
	if (app->time == -1)
		exit_cub3d(app, EXIT_FAILURE);
	frametime = app->time - oldtime;
	rotate_speed = frametime * ROTATE_SPEED;
	old_dir_x = app->player.dir_x;
	app->player.dir_x = old_dir_x * cos(-rotate_speed) - app->player.dir_y * sin(-rotate_speed);
	app->player.dir_y = old_dir_x * sin(-rotate_speed) + app->player.dir_y * cos(-rotate_speed);
	old_plane_x = app->player.plane_x;
	app->player.plane_x = old_plane_x * cos(-rotate_speed) - app->player.plane_y * sin(-rotate_speed);
	app->player.plane_y = old_plane_x * sin(-rotate_speed) + app->player.plane_y * cos(-rotate_speed);
}
