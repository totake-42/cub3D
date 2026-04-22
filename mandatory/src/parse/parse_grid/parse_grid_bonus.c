/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:26:36 by itakumi           #+#    #+#             */
/*   Updated: 2026/04/17 18:49:33 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "parse.h"
#include "status.h"
#include "utils.h"
#include <stddef.h>

/*
	CHECK LIST
	1.
*/

static void	analyze_file_dimensions(const char **file_lines, size_t *row_len,
		size_t *max_col_len)
{
	size_t	col_len;

	*row_len = 0;
	while (*file_lines != NULL)
	{
		col_len = ft_strlen(*file_lines);
		if (col_len > *max_col_len)
			*max_col_len = col_len;
		(*row_len)++;
		file_lines++;
	}
}

t_status	parse_grid(const char **file_lines, t_map *map_data)
{
	size_t	row_len;
	size_t	max_col_len;

	if (file_lines == NULL)
		return (STATUS_ERROR);
	max_col_len = 0;
	analyze_file_dimensions(file_lines, &row_len, &max_col_len);
	map_data->grid_height = row_len;
	map_data->grid_width = max_col_len;
	if (validate_characters(file_lines) == STATUS_ERROR)
		return (STATUS_ERROR);
	if (validate_player(file_lines, map_data) == STATUS_ERROR)
		return (STATUS_ERROR);
	if (validate_walls(file_lines, map_data) == STATUS_ERROR)
		return (STATUS_ERROR);
	map_data->grid = duplicate_file_lines(file_lines, map_data->grid_height);
	if (map_data->grid == NULL)
		return (STATUS_ERROR);
	return (STATUS_OK);
}
