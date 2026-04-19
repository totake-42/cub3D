/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:29:12 by itakumi           #+#    #+#             */
/*   Updated: 2026/04/19 19:27:15 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"
#include "libft.h"
#include "parse.h"
#include "status.h"
#include "utils.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/types.h>

t_status	parse_map(t_cub3d *app, const char *input_file)
{
	char	**file_lines;
	char	**file_lines_head;

	if (app == NULL || input_file == NULL)
		return (STATUS_ERROR);
	if (validate_input_file_extension(input_file) == false)
		return (ft_putendl_fd(ERROR_INVALID_MAP_EXTENSION, STDERR_FILENO),
			STATUS_ERROR);
	file_lines = load_input_file(input_file);
	if (file_lines == NULL)
		return (STATUS_ERROR);
	file_lines_head = file_lines;
	app->map_data = ft_calloc(sizeof(t_map), 1);
	if (app->map_data == NULL)
		return (free_array((void **)file_lines_head), STATUS_ERROR);
	if (parse_identifiers((const char ***)&file_lines,
			app->map_data) == STATUS_ERROR)
		return (free_map(&(app->map_data)), \
			free_array((void **)file_lines_head), STATUS_ERROR);
	if (parse_grid((const char **)file_lines, app->map_data) == STATUS_ERROR)
		return (free_map(&(app->map_data)), \
			free_array((void **)file_lines_head), STATUS_ERROR);
	return (free_array((void **)file_lines_head), STATUS_OK);
}

// #include <assert.h>
// int	main(void)k
// {
// 	char	*test0 = "";
// 	char	*test1 = "cub";
// 	char	*test2 = "b";
// 	char	*test3 = NULL;
// 	char	*test4 = ".cub";
// 	char	*test5 = "..cub";
// 	char	*test6 = "valid.cub";
// 	assert(validate_input_file() == false);
// 	assert(validate_input_file(test1) == false);
// 	assert(validate_input_file(test2) == false);
// 	assert(validate_input_file(test3) == false);
// 	assert(validate_input_file(test4) == true);
// 	assert(validate_input_file(test5) == true);
// 	assert(validate_input_file(test6) == true);
// 	return (0);
// }
