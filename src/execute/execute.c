/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:47:39 by tigarashi         #+#    #+#             */
/*   Updated: 2026/03/12 00:10:17 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <X11/X.h>
#include <stdlib.h>

#include "cub3d.h"
#include "status.h"
#include "render.h"
#include "utils.h"

static int	close_window(void *param);

t_status	execute_game(t_cub3d *app)
{
	void	*param;

	if (app == NULL)
		return (STATUS_ERROR);
	init_player(&(app->player), app->map_data);
	param = (void *)app;
	mlx_loop_hook(app->view->mlx_ptr, render, param);
	// only windows
	mlx_hook(app->view->win_ptr, KeyPress, KeyPressMask, handle_keypress, param);
	mlx_hook(app->view->win_ptr, DestroyNotify, StructureNotifyMask, close_window, param);
	mlx_loop(app->view->mlx_ptr);
	return (STATUS_OK);
}

static int	close_window(void *param)
{
	t_cub3d *app;

	app = (t_cub3d *)param;
	exit_cub3d(app, EXIT_SUCCESS);
	return (-1);
}