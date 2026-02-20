/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:07:34 by itakumi           #+#    #+#             */
/*   Updated: 2026/02/20 13:47:15 by totake           ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_cub3d	app;

	if (argc != 2)
	{
		ft_putendl_fd(ERROR_ARGC, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	app.map_data = NULL;
	app.view = NULL;
	if (parse_map(&app, argv[1]) == STATUS_ERROR)
		return (EXIT_FAILURE);
	if (init_view(&app) == STATUS_ERROR)
	{
		free_map(&(app.map_data));
		return (EXIT_FAILURE);
	}
	mlx_loop_hook(app.view->mlx_ptr, game_loop, &app);
	mlx_hook(app.view->win_ptr, 2, 1L << 0, handle_keypress, &app);
	mlx_hook(app.view->win_ptr, 17, 0, handle_close, &app);
	mlx_loop(app.view->mlx_ptr);
	free_view(&(app.view));
	free_map(&(app.map_data));
	return (EXIT_SUCCESS);
}
