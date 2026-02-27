/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:50:15 by itakumi           #+#    #+#             */
/*   Updated: 2026/02/24 14:45:50 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

#include "cub3d.h"
#include "parse.h"
#include "status.h"
#include "utils.h"

static t_element_config	g_config_table[] = {
{.identifier = "NO", .is_set = false, \
	.func = set_texture_path, .offset = offsetof(t_map, north_tex_path)},
{.identifier = "SO", .is_set = false, \
	.func = set_texture_path, .offset = offsetof(t_map, south_tex_path)},
{.identifier = "WE", .is_set = false, \
	.func = set_texture_path, .offset = offsetof(t_map, west_tex_path)},
{.identifier = "EA", .is_set = false, \
	.func = set_texture_path, .offset = offsetof(t_map, east_tex_path)},
{.identifier = "F", .is_set = false, \
	.func = set_layer_color, .offset = offsetof(t_map, floor_color)},
{.identifier = "C", .is_set = false, \
	.func = set_layer_color, .offset = offsetof(t_map, ceiling_color)}
};

static const int		g_config_table_len = \
	sizeof(g_config_table) / sizeof(g_config_table[0]);

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
		print_error((char *)line, ERROR_INVALID_IDENTIFIER);
		return (STATUS_ERROR);
	}
	else if (g_config_table[config_idx].is_set == true)
	{
		print_error((char *)line, ERROR_DUPLICATE_IDENTIFIER);
		return (STATUS_ERROR);
	}
	return (STATUS_OK);
}

static t_status	process_config_line(
const char *line, t_map *map_data, int *set_count)
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
		print_error((char *)line, ERROR_INVALID_IDENTIFIER_VALUE);
		return (STATUS_ERROR);
	}
	if (g_config_table[idx].func(map_data, idx, line) == STATUS_ERROR)
		return (STATUS_ERROR);
	return (STATUS_OK);
}

t_status	parse_identifiers(const char ***file_lines, t_map *map_data)
{
	int			set_count;
	const char	*line;

	if (file_lines == NULL || *file_lines == NULL || map_data == NULL)
		return (STATUS_ERROR);
	set_count = 0;
	while (**file_lines != NULL && set_count <= g_config_table_len)
	{
		line = **file_lines;
		if (ft_strequal(line, "") == false)
		{
			if (process_config_line(line, map_data, &set_count) == STATUS_ERROR)
				return (STATUS_ERROR);
		}
		(*file_lines)++;
	}
	if (set_count < g_config_table_len)
	{
		ft_putendl_fd(ERROR_NO_ENOUGH_ELEMENTS, STDERR_FILENO);
		return (STATUS_ERROR);
	}
	return (STATUS_OK);
}
// // 空行とは、改行のみの行を指す。
// // それ以外はエラーとして弾く。
// // 1. grid までの文字列を検証する
// // (空行はスキップする)
// // 既に、is_setがtrueの状態で、同じ識別子が来たら、弾く。

// // should use strequal
// // spaceまでの、長さを図る

// その後に１単語を読み取る。
// color系と, texture系で分岐させる
// F, Cに関しては、0~ 255 までの整数ではなかったら弾く。
// 整数が、３つなかったら、数値が足りないとして弾く
// 値を抽出する
// その後に、改行または、null文字ではなかったら、エラーとする
// -> 他の単語が有るということ

/* file_line identifier test */
// int	main(void)
// {
// 	char	*file_lines[] =
// 	{
// 		"NO ", "NOOO", "INVALID", "", NULL
// 	};
// 	t_status status = parse_identifiers(file_lines);
// 	printf("status: %d\n", status);
// 	return (0);
// }

// #include <stdio.h>
// int	main(void)
// {
// 	const char	*t1 = ft_strdup("NO /north");
// 	const char	*t2 = ft_strdup("SO /south");
// 	const char	*t3 = ft_strdup("WE /west");
// 	const char	*t4 = ft_strdup("EA /east");
// 	const char 	*t5 = ft_strdup("F 0,255,0");
// 	const char	*t6 = ft_strdup("C 0,0,255");
// 	const char	**file_lines1 = malloc(sizeof(const char *) * 7);
// 	file_lines1[0] = t1;
// 	file_lines1[1] = t2;
// 	file_lines1[2] = t3;
// 	file_lines1[3] = t4;
// 	file_lines1[4] = t5;
// 	file_lines1[5] = t6;
// 	file_lines1[6] = NULL;
// 	t_map	map_data;

// 	t_status	status = parse_identifiers(&file_lines1, &map_data);
// 	printf("status: %d\n", status);
// 	return (0);
// }
