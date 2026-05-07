/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:08:40 by itakumi           #+#    #+#             */
/*   Updated: 2026/05/04 18:53:44 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "parse.h"
#include "status.h"
#include "utils.h"

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
	if (is_set_player == false)
	{
		print_error(NULL, ERROR_NO_PLAYER);
		return (STATUS_ERROR);
	}
	return (STATUS_OK);
}
