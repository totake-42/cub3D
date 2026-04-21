/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:08:40 by itakumi           #+#    #+#             */
/*   Updated: 2026/04/21 17:04:05 by itakumi          ###   ########.fr       */
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
	return (STATUS_OK);
}

// #include <assert.h>
// int	main(void)
// {
// 	const char  *m1 = ft_strdup("11111");
//     const char  *m2 = ft_strdup("1N001");
//     const char  *m3 = ft_strdup("10N01"); // 真ん中にプレイヤー(North向き)
//     const char  *m4 = ft_strdup("10001");
//     const char  *m5 = ft_strdup("11111");
// 	const char	**file_lines1 = malloc(sizeof(const char *) * 6);
// 	file_lines1[0] = m1;
//     file_lines1[1] = m2;
//     file_lines1[2] = m3;
//     file_lines1[3] = m4;
//     file_lines1[4] = m5;
//     file_lines1[5] = NULL;
// 	t_map	map_data = {0};
// 	assert(validate_player(file_lines1, &map_data) == STATUS_ERROR);
// 	puts("Test1 OK!!");
// 	const char	*m6 = ft_strdup("10001");
// 	file_lines1[1] = m6;
// 	assert(validate_player(file_lines1, &map_data) == STATUS_OK);
// 	puts("Test2 OK!!");
// 	return (0);
// }
