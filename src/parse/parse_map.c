/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:29:12 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/05 16:14:17 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <stdbool.h>
#include <stdio.h>
#include "libft.h"
#include "get_next_line.h"

#include "cub3d.h"
#include "status.h"
#include "parse.h"
#include "utils.h"

char	**parse_map(t_cub3d *app, const char *input_file)
{
	char	**file_lines;

	if (app == NULL || input_file == NULL)
		return (NULL);
	if (validate_input_file_extension(input_file) == false)
	{
		ft_putendl_fd(ERROR_INVALID_MAP_EXTENSION, STDERR_FILENO);
		return (NULL);
	}
	file_lines = load_input_file(input_file);
	if (file_lines == NULL)
		return (NULL);
	if (parse_identifiers(file_lines) == STATUS_ERROR)
	{
		free_array((void **)file_lines);
		return (NULL);
	}
	if (parse_grid(file_lines) == STATUS_ERROR)
	{
		free_array((void **)file_lines);
		return (NULL);
	}
	return (file_lines);
}

// #include <assert.h>
// int	main(void)
// {
// 	char	*test0 = "";
// 	char	*test1 = "cub";
// 	char	*test2 = "b";
// 	char	*test3 = NULL;
// 	char	*test4 = ".cub";
// 	char	*test5 = "..cub";
// 	char	*test6 = "valid.cub";
// 	assert(validate_input_file(test0) == false);
// 	assert(validate_input_file(test1) == false);
// 	assert(validate_input_file(test2) == false);
// 	assert(validate_input_file(test3) == false);
// 	assert(validate_input_file(test4) == true);
// 	assert(validate_input_file(test5) == true);
// 	assert(validate_input_file(test6) == true);
// 	return (0);
// }
