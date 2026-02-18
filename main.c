/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:07:34 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/06 16:55:46 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line_no_nl.h"
#include "libft.h"

#include "cub3d.h"
#include "init.h"
#include "utils.h"
#include "parse.h"
#include "utils.h"

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
	return (EXIT_SUCCESS);
}
