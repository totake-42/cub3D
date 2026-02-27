/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:47:39 by tigarashi         #+#    #+#             */
/*   Updated: 2026/02/27 20:01:29 by tigarashi        ###   ########.fr       */
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
	param = (void *)app;
	if (mlx_expose_hook(app->view->win_ptr, render, param) == -1)
		exit_cub3d(app, EXIT_FAILURE);
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