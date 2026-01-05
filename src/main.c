/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:07:34 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/05 14:12:46 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

#include "cub3d.h"
#include "init.h"
#include "utils.h"
#include "parse.h"
#include "utils.h"

int	main(int argc, char **argv)
{
	t_cub3d	app;
	char	**map_temp;

	if (argc != 2)
	{
		ft_putendl_fd(ERROR_ARGC, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	app.map_data = NULL;
	app.view = NULL;
	map_temp = parse_map(&app, argv[1]);
	if (map_temp == NULL)
		return (EXIT_FAILURE);
	if (init_view(&app) == STATUS_ERROR)
	{
		free_map(&(app.map_data));
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
