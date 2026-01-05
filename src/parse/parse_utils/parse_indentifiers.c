/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_indentifiers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:50:15 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/05 16:20:18 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

#include "cub3d.h"
#include "status.h"
#include "parse.h"
#include "utils.h"

static t_element_config	config_table[] =
{
	{.identifier = "NO", .is_set = false},
	{.identifier = "SO", .is_set = false},
	{.identifier = "WE", .is_set = false},
	{.identifier = "EA", .is_set = false},
	{.identifier = "F", .is_set = false},
	{.identifier = "C", .is_set = false}
}; 
static const int		config_table_len =
	sizeof(config_table) / sizeof(config_table[0]);

// 空行とは、改行のみの行を指す。
// それ以外はエラーとして弾く。
// 1. grid までの文字列を検証する
// (空行はスキップする)
// 既に、is_setがtrueの状態で、同じ識別子が来たら、弾く。

int	find_identifier_index(const char *file_line)
{
	int			index;
	
	index = 0;
	while (index < config_table_len)
	{
		if (ft_strncmp(file_line, config_table[index].identifier, \
			ft_strlen(config_table[index].identifier)) == 0)
			return (index);
		index++;
	}
	return (NOT_FOUND_IDENTIFIER);
}

t_status	parse_identifiers(char **file_lines)
{
	int						idx;

	while (*file_lines != NULL)
	{
		if (strequal(*file_lines, "\n") == true)
		{
			file_lines++;
			continue ;
		}
		idx = find_identifier_index(*file_lines);
		if (idx == NOT_FOUND_IDENTIFIER)
		{
			print_error(*file_lines, ERROR_INVALID_IDENTIFIER);
			return (STATUS_ERROR);
		}
		// while (**file_lines != '\0' && **file_lines != '\n')
		// {
				
		// 	(*file_lines)++;
		// }
		file_lines++;
	}
	return (STATUS_OK);
}

// int	main(void)
// {
// 	char	*file_lines[] =
// 	{
// 		"NO ", "INVALID", "", NULL
// 	};
// 	t_status status = parse_identifiers(file_lines);
// 	printf("status: %d\n", status);
// 	return (0);
// }
