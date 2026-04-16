/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:26:36 by itakumi           #+#    #+#             */
/*   Updated: 2026/02/20 13:33:03 by totake           ###   ########.fr       */
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

/*
	char	**grid;
	int		grid_width;
	int		grid_height;
	int		player_x;
	int		player_y;
	int		player_dir;
*/

/*
	1. gridの最大の高さと幅を代入する
	2. playerの文字列が来たら、player変数系に代入する(playerはただ一人であるので、
		bool値で管理する必要が有る)-> 管理するテーブルが必要
	3. gridの情報をそのまま書き込む（ft_strdupする）
	4. 有効な文字以外が来たら弾かなければならない。
	5. playerの８方位すべてが1だったらどうする？
*/

// is_setがすべて登録されていたら、OK
// 2. gridが閉じられているかどうかを検証する
// (grid の空行は許されない)
// コピー元のfile_linesはインクリメントしない
// 最後まで見る
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
