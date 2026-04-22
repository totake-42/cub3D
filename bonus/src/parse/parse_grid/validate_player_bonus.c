/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_player_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:15:51 by totake            #+#    #+#             */
/*   Updated: 2026/04/22 13:15:56 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"
#include "parse_bonus.h"
#include "status_bonus.h"
#include "utils_bonus.h"

static bool	is_player_character(int c)
{
	const unsigned char	uc = (const unsigned char)c;

	return (uc == 'N' || uc == 'S' || uc == 'E' || uc == 'W');
}

static t_status	process_validate_player(const char *line, t_map *map_data,
		bool *is_set_player, int row_count)
{
	const char	*line_temp;

	line_temp = line;
	while (*line != '\0')
	{
		if (is_player_character(*line) == true)
		{
			if (*is_set_player == true)
			{
				print_error(NULL, ERROR_TOO_MANY_PLAYERS);
				return (STATUS_ERROR);
			}
			map_data->player_x = line - line_temp;
			map_data->player_y = row_count;
			*is_set_player = true;
		}
		line++;
	}
	return (STATUS_OK);
}

t_status	validate_player(const char **file_lines, t_map *map_data)
{
	const char	*line;
	bool		is_set_player;
	int			row_count;

	if (file_lines == NULL)
		return (STATUS_ERROR);
	is_set_player = false;
	row_count = 0;
	while (*file_lines != NULL)
	{
		line = *file_lines;
		if (process_validate_player(line, map_data, &is_set_player,
				row_count) == STATUS_ERROR)
			return (STATUS_ERROR);
		row_count++;
		file_lines++;
	}
	return (STATUS_OK);
}
