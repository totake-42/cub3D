/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:46:09 by tigarashi         #+#    #+#             */
/*   Updated: 2026/02/27 16:46:49 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stddef.h>

#include "cub3d.h"
#include "render.h"

/**
 * @fn handle_key
 * @brief keypress handling
 * @param ( cub3d_ptr ) all information.
 * @return success or failure
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
