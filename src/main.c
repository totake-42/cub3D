/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:07:34 by itakumi           #+#    #+#             */
/*   Updated: 2026/03/11 23:25:14 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line_no_nl.h"
#include "libft.h"

#include "cub3d.h"
#include "init.h"
#include "execute.h"
#include "utils.h"
#include "parse.h"
#include "utils.h"

void	debug_grid(char **grid)
{
	for (int i = 0; grid[i] != NULL; i++) {
			printf("%s\n", grid[i]);
	}
}

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
	app.time = get_time();
	if (app.time == -1)
		return (EXIT_FAILURE);
	if (parse_map(&app, argv[1]) == STATUS_ERROR)
		return (EXIT_FAILURE);
	for (int i = 0; i < DIR_COUNT; i++)
	{
		printf("%s\n", app.map_data->texture_pathes[i]);
	}
	if (init_view(&app) == STATUS_ERROR)
	{
		free_map(&(app.map_data));
		return (EXIT_FAILURE);
	}
	if (set_texture_image(&app) == STATUS_ERROR)
		exit_cub3d(&app, EXIT_FAILURE);
	init_minimap(&app);
	if (execute_game(&app) == STATUS_ERROR)
		exit_cub3d(&app, EXIT_FAILURE);
	exit_cub3d(&app, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
