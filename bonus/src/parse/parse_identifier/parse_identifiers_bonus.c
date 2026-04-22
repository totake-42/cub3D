/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifiers_bonus.c                                        :+:      :+:    :+:   *//*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:50:15 by itakumi           #+#    #+#             */
/*   Updated: 2026/04/21 18:01:29 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"
#include "parse_bonus.h"
#include "status_bonus.h"
#include "utils_bonus.h"
#include <stddef.h>

static t_element_config	g_config_table[] = {
{.identifier = "NO", .is_set = false, .func = set_texture_path, \
.offset = offsetof(t_map, north_tex_path)},
{.identifier = "SO", .is_set = false, .func = set_texture_path, \
.offset = offsetof(t_map, south_tex_path)},
{.identifier = "WE", .is_set = false, .func = set_texture_path, \
.offset = offsetof(t_map, west_tex_path)},
{.identifier = "EA", .is_set = false, .func = set_texture_path, \
.offset = offsetof(t_map, east_tex_path)},
{.identifier = "F", .is_set = false, .func = set_layer_color, \
.offset = offsetof(t_map, floor_color)},
{.identifier = "C", .is_set = false, .func = set_layer_color, \
.offset = offsetof(t_map, ceiling_color)}
};

static const int		g_config_table_len = sizeof(g_config_table) \
	/ sizeof(g_config_table[0]);

static int	find_identifier_index(const char *line)
{
	int	index;
	int	id_len;

	index = 0;
	while (index < g_config_table_len)
	{
		id_len = ft_strlen(g_config_table[index].identifier);
		if (ft_strncmp(line, g_config_table[index].identifier, id_len) == 0
			&& line[id_len] == ' ')
			return (index);
		index++;
	}
	return (NOT_FOUND_IDENTIFIER);
}

static t_status	validate_identifier_status(int config_idx, const char *line)
{
	if (config_idx == NOT_FOUND_IDENTIFIER)
	{
		print_error(line, ERROR_INVALID_IDENTIFIER);
		return (STATUS_ERROR);
	}
	else if (g_config_table[config_idx].is_set == true)
	{
		print_error(line, ERROR_DUPLICATE_IDENTIFIER);
		return (STATUS_ERROR);
	}
	return (STATUS_OK);
}

static t_status	process_config_line(const char *line, t_map *map_data,
		int *set_count)
{
	int	idx;

	idx = find_identifier_index(line);
	if (validate_identifier_status(idx, line) == STATUS_ERROR)
		return (STATUS_ERROR);
	g_config_table[idx].is_set = true;
	(*set_count)++;
	line += ft_strlen(g_config_table[idx].identifier);
	while (*line == ' ')
		line++;
	if (*line == '\0')
	{
		print_error(g_config_table[idx].identifier,
			ERROR_EMPTY_TEXTURE_PATH_CONTENT);
		return (STATUS_ERROR);
	}
	if (g_config_table[idx].func(map_data, g_config_table[idx].offset,
			line) == STATUS_ERROR)
		return (STATUS_ERROR);
	return (STATUS_OK);
}

static t_status	parse_single_line(const char *line, t_map *map_data,
		int *set_count, bool *is_map)
{
	int	config_idx;

	if (ft_strequal(line, "") == true)
		return (STATUS_OK);
	config_idx = find_identifier_index(line);
	if (config_idx == NOT_FOUND_IDENTIFIER)
	{
		if (is_valid_map_line(line) == true)
		{
			*is_map = true;
			return (STATUS_OK);
		}
		print_error(line, ERROR_INVALID_IDENTIFIER);
		return (STATUS_ERROR);
	}
	return (process_config_line(line, map_data, set_count));
}

t_status	parse_identifiers(const char ***file_lines, t_map *map_data)
{
	int		set_count;
	bool	is_map;

	set_count = 0;
	is_map = false;
	while (**file_lines != NULL)
	{
		if (parse_single_line(**file_lines, map_data, &set_count,
				&is_map) == STATUS_ERROR)
			return (STATUS_ERROR);
		if (is_map == true)
			break ;
		(*file_lines)++;
	}
	if (set_count != g_config_table_len)
	{
		print_error(NULL, ERROR_MISSING_IDENTIFIERS_BEFORE_MAP);
		return (STATUS_ERROR);
	}
	return (STATUS_OK);
}
