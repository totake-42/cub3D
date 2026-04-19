/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_indentifiers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:50:15 by itakumi           #+#    #+#             */
/*   Updated: 2026/04/18 16:46:44 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "parse.h"
#include "status.h"
#include "utils.h"
#include <stddef.h>

static t_element_config g_config_table[] = {{.identifier = "NO",
                                             .is_set = false,
                                             .func = set_texture_path,
                                             .offset = offsetof(t_map,
                                                                north_tex_path)},
                                            {.identifier = "SO", .is_set = false, .func = set_texture_path, .offset = offsetof(t_map, south_tex_path)},
                                            {.identifier = "WE", .is_set = false, .func = set_texture_path, .offset = offsetof(t_map, west_tex_path)},
                                            {.identifier = "EA",
                                             .is_set = false,
                                             .func = set_texture_path,
                                             .offset = offsetof(t_map,
                                                                east_tex_path)},
                                            {.identifier = "F", .is_set = false, .func = set_layer_color, .offset = offsetof(t_map, floor_color)},
                                            {.identifier = "C", .is_set = false, .func = set_layer_color, .offset = offsetof(t_map, ceiling_color)}};

static const int g_config_table_len = sizeof(g_config_table)
                                      / sizeof(g_config_table[0]);

static int find_identifier_index(const char* line)
{
    int index;
    int id_len;

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

static t_status validate_identifier_status(int config_idx, const char* line)
{
    if (config_idx == NOT_FOUND_IDENTIFIER)
    {
        print_error((char*)line, ERROR_INVALID_IDENTIFIER);
        return (STATUS_ERROR);
    }
    else if (g_config_table[config_idx].is_set == true)
    {
        print_error((char*)line, ERROR_DUPLICATE_IDENTIFIER);
        return (STATUS_ERROR);
    }
    return (STATUS_OK);
}

static t_status process_config_line(const char* line, t_map* map_data,
                                    int* set_count)
{
    int idx;

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
        print_error(g_config_table[idx].identifier, ERROR_EMPTY_TEXTURE_PATH_CONTENT);
        return (STATUS_ERROR);
    }
    if (g_config_table[idx].func(map_data, g_config_table[idx].offset,
                                 line)
        == STATUS_ERROR)
        return (STATUS_ERROR);
    return (STATUS_OK);
}

static bool	is_valid_map_line(const char *line)
{
	const char	*map_characters = "01NSEW ";
	const int	map_characters_len = ft_strlen(map_characters);
	int			i;

	while (*line != '\0')
	{
		i = 0;
		while (map_characters[i] != '\0')
		{
			if (*line == map_characters[i])
			{
				break ;
			}	
			i++;
		}
		if (i == map_characters_len)
			return (false);
		line++;
	}
	return (true);
}

t_status	parse_identifiers(const char ***file_lines, t_map *map_data)
{
	int			set_count;
	const char	*line;
	int			config_idx;

	set_count = 0;
	while (**file_lines != NULL)
	{
		line = **file_lines;
		if (ft_strequal(line, "") == true)
		{
			(*file_lines)++;
			continue ;
		}
		config_idx = find_identifier_index(line);
		if (config_idx == NOT_FOUND_IDENTIFIER)
		{
			if (is_valid_map_line(line) == true)
				break ;
			else
			{
				print_error((char *)line, ERROR_INVALID_IDENTIFIER);
				return (STATUS_ERROR);
			}
		}
		if (process_config_line(line, map_data, &set_count) == STATUS_ERROR)
			return (STATUS_ERROR);
		(*file_lines)++;
	}
	if (set_count != g_config_table_len)
	{
		ft_putendl_fd(ERROR_MISSING_IDENTIFIERS_BEFORE_MAP, STDERR_FILENO);
		return (STATUS_ERROR);
	}
	return (STATUS_OK);
}
