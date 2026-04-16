/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:00:00 by itakumi           #+#    #+#             */
/*   Updated: 2026/04/16 17:42:44 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"
#include "mlx.h"
#include "utils.h"

/*
 * Handle keyboard input
 * W/A/S/D: movement
 * Left/Right arrow: rotation
 * ESC: exit
 */
int	handle_keypress(int keycode, t_cub3d *app)
{
	if (keycode == KEY_ESC)
		mlx_loop_end(app->view->mlx_ptr);
	else if (keycode == KEY_W)
		move_forward(app);
	else if (keycode == KEY_S)
		move_backward(app);
	else if (keycode == KEY_A)
		move_left(app);
	else if (keycode == KEY_D)
		move_right(app);
	else if (keycode == KEY_LEFT)
		rotate_left(app);
	else if (keycode == KEY_RIGHT)
		rotate_right(app);
	return (0);
}

/**
 * if the window close button is pressed
 * exit the game
 */
int	handle_close(t_cub3d *app)
{
	mlx_loop_end(app->view->mlx_ptr);
	return (0);
}
