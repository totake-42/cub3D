/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:08:40 by itakumi           #+#    #+#             */
/*   Updated: 2026/03/12 01:00:50 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "cub3d.h"
#include "status.h"
#include "parse.h"
#include "utils.h"

static const t_player_config	g_config_table[] = {
{.state = "N", .func = set_player_north},
{.state = "S", .func = set_player_south},
{.state = "E", .func = set_player_east},
{.state = "W", .func = set_player_west}
};
static const size_t	g_config_table_len = sizeof(g_config_table) / sizeof(g_config_table[0]);

// playerが複数人いても対応できるようにする
// 本当は、設定ファイルのような概念を用いて、playerの検証を行うのがよいのかも
static int	find_state_index(int c)
{
	const  char uc[] = {c, '\0'};
	size_t				i;

	i = 0;
	while (i < g_config_table_len)
	{
		if (ft_strequal(uc, g_config_table[i].state) == true)
			return (i);
		i++;
	}
	return (NOT_FOUND_IDENTIFIER);
}

static void	set_player_dir(t_map *map_data, int c)
{
	int					idx;

	idx = find_state_index(c);
	if (idx == NOT_FOUND_IDENTIFIER)
		return ;
	g_config_table[idx].func(map_data);
}

static t_status	process_validate_player(
const char *line, t_map *map_data, bool *is_set_player, int row_count)
{
	const char	*line_temp;

	line_temp = line;
	while (*line != '\0')
	{
		if (find_state_index(*line) != NOT_FOUND_IDENTIFIER)
		{
			if (*is_set_player == true)
			{
				ft_putendl_fd(ERROR_TOO_MANY_PLAYERS, STDERR_FILENO);
				return (STATUS_ERROR);
			}
			map_data->player_x = line - line_temp;
			map_data->player_y = row_count;
			set_player_dir(map_data, *line);
			*is_set_player = true;
		}
		line++;
	}
	return (STATUS_OK);
}

// validate_objectという関数にするのがが良いかもしれない
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
		if (process_validate_player(line, map_data, &is_set_player, row_count) \
			== STATUS_ERROR)
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
