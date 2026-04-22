/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:12:41 by totake            #+#    #+#             */
/*   Updated: 2026/04/22 13:12:44 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "game_bonus.h"
#include "mlx.h"
#include "utils_bonus.h"

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

/*
 * Handle expose event (window redraw)
 * Called when window is uncovered or resized
 */
int	handle_expose(t_cub3d *app)
{
	render(app);
	mlx_put_image_to_window(app->view->mlx_ptr, app->view->win_ptr,
		app->view->img_ptr, 0, 0);
	return (0);
}
