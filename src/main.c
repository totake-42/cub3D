/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:07:34 by itakumi           #+#    #+#             */
/*   Updated: 2026/04/19 11:41:27 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"
#include "get_next_line_no_nl.h"
#include "init.h"
#include "libft.h"
#include "mlx.h"
#include "parse.h"
#include "utils.h"
#include <stdlib.h>

static void	cleanup_game(t_cub3d *app)
{
	free_textures(app);
	free_view(&(app->view));
	free_map(&(app->map_data));
}

static int	init_game(t_cub3d *app, char *map_file)
{
	app->map_data = NULL;
	app->view = NULL;
	if (parse_map(app, map_file) == STATUS_ERROR)
		return (STATUS_ERROR);
	if (init_view(app) == STATUS_ERROR)
	{
		free_map(&(app->map_data));
		return (STATUS_ERROR);
	}
	if (init_textures(app) == STATUS_ERROR)
	{
		free_view(&(app->view));
		free_map(&(app->map_data));
		return (STATUS_ERROR);
	}
	init_player(app);
	return (STATUS_OK);
}

/*
 * Setup MLX event hooks
 * - mlx_loop_hook: Continuously run game_loop when idle
 * - mlx_hook (KeyPress, KeyPressMask): KeyPress event handler
 *   KeyPressMask tells X11 server to forward keyboard events
 * - mlx_hook (DestroyNotify, 0): DestroyNotify event (window close button)
 *   No mask needed for structure events
 * - mlx_hook (Expose, ExposureMask): Expose event (window redraw)
 *   ExposureMask tells X11 server to forward expose events
 */
static void	setup_hooks(t_cub3d *app)
{
	mlx_loop_hook(app->view->mlx_ptr, game_loop, app);
	mlx_hook(app->view->win_ptr, KeyPress, KeyPressMask, handle_keypress, app);
	mlx_hook(app->view->win_ptr, DestroyNotify, 0, handle_close, app);
	mlx_hook(app->view->win_ptr, Expose, ExposureMask, handle_expose, app);
}

int	main(int argc, char **argv)
{
	t_cub3d	app;

	if (argc != 2)
	{
		ft_putendl_fd(ERROR_ARGC, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (init_game(&app, argv[1]) == STATUS_ERROR)
		return (EXIT_FAILURE);
	setup_hooks(&app);
	mlx_loop(app.view->mlx_ptr);
	cleanup_game(&app);
	return (EXIT_SUCCESS);
}
