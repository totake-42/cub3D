/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_walls_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:16:08 by totake            #+#    #+#             */
/*   Updated: 2026/05/04 20:55:44 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"
#include "parse_bonus.h"
#include "status_bonus.h"
#include "utils_bonus.h"

static t_status	check_4_direction(const char **file_lines, int x, int y)
{
	if (x <= 0 || file_lines[y][x + 1] == '\0'
		|| y <= 0 || file_lines[y + 1] == NULL)
		return (STATUS_ERROR);
	if (file_lines[y][x - 1] == ' ' || file_lines[y][x + 1] == ' ')
		return (STATUS_ERROR);
	if ((size_t)x >= ft_strlen(file_lines[y - 1])
		|| (size_t)x >= ft_strlen(file_lines[y + 1]))
		return (STATUS_ERROR);
	if (file_lines[y - 1][x] == ' ' || file_lines[y + 1][x] == ' ')
		return (STATUS_ERROR);
	return (STATUS_OK);
}

/**
 * @fn  validate_map_boundaries
 * @param (file_lines) @param (map_data)
 * @brief validate all '0' for 4 direction.
 */
static t_status	validate_map_boundaries(const char **file_lines)
{
	int		x;
	int		y;
	bool	is_first_emptyline;

	y = 0;
	is_first_emptyline = false;
	while (file_lines[y] != NULL)
	{
		x = 0;
		if (file_lines[y][x] == '\0')
			is_first_emptyline = true;
		while (file_lines[y][x] != '\0')
		{
			if (is_first_emptyline == true)
				return (print_error(NULL, ERROR_MAP_IS_SEPARATED_EMPTY_LINES),
					STATUS_ERROR);
			if (file_lines[y][x] != '0')
			{
				x++;
				continue ;
			}
			if (check_4_direction(file_lines, x, y) == STATUS_ERROR)
				return (print_error(NULL, ERROR_UNCLOSED_MAP),
					STATUS_ERROR);
			x++;
		}
		y++;
	}
	return (STATUS_OK);
}

t_status	validate_walls(const char **file_lines, t_map *map_data)
{
	char	**file_lines_cpy;

	if (map_data->grid_height > MAX_GRID_SIZE_HEIGHT
		|| map_data->grid_width > MAX_GRID_SIZE_WIDTH)
	{
		print_error(NULL, ERROR_GRID_SIZE);
		return (STATUS_ERROR);
	}
	file_lines_cpy = duplicate_file_lines(file_lines, map_data->grid_height);
	if (file_lines_cpy == NULL)
		return (STATUS_ERROR);
	if (validate_map_boundaries((const char **)file_lines_cpy) == STATUS_ERROR)
	{
		free_array((void **)file_lines_cpy);
		return (STATUS_ERROR);
	}
	free_array((void **)file_lines_cpy);
	return (STATUS_OK);
}

/*
	Validate walls Test

*/
// #include <stdio.h>
// #include <assert.h>
// int	main(void)
// {
// 	puts("\n -------------- test1 (valid case) ---------------");
// 	const char  *m1 = ft_strdup("11111");
//     const char  *m2 = ft_strdup("1N000");
//     const char  *m3 = ft_strdup("10001");
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
// 	map_data.player_x = 1;
// 	map_data.player_y = 1;
// 	printf("x: %d\n", map_data.player_x);
// 	printf("y: %d\n", map_data.player_y);
// 	map_data.grid_width = 5;
// 	map_data.grid_height = 5;
// 	assert(validate_walls(file_lines1, &map_data) == STATUS_ERROR);
// 	const char	*m6 = ft_strdup("10001");
// 	file_lines1[1] = m6;
// 	assert(validate_walls(file_lines1, &map_data) == STATUS_OK);
// 	puts("Test1 OK!!");

// 	puts("\n----- test2 (space case) ------------");
// 	m1 = ft_strdup("11111   ");
//     m2 = ft_strdup("1N001");
//     m3 = ft_strdup("10001");
//     m4 = ft_strdup("10001");
//     m5 = ft_strdup("11111");
// 	file_lines1[0] = m1;
//     file_lines1[1] = m2;
//     file_lines1[2] = m3;
//     file_lines1[3] = m4;
//     file_lines1[4] = m5;
//     file_lines1[5] = NULL;
// 	assert(validate_walls(file_lines1, &map_data) == STATUS_OK);
// 	puts("Test2 OK!!");

// 	puts("\n----- test3 (space case) ------------");
// 	m1 = ft_strdup("11111   ");
// 	m2 = ft_strdup("1N001");
// 	m3 = ft_strdup("10001");
// 	m4 = ft_strdup("10001");
// 	m5 = ft_strdup("11111");
// 	file_lines1[0] = m1;
//     file_lines1[1] = m2;
//     file_lines1[2] = m3;
//     file_lines1[3] = m4;
//     file_lines1[4] = m5;
//     file_lines1[5] = NULL;
// 	assert(validate_walls(file_lines1, &map_data) == STATUS_OK);
// 	puts("Test3 OK!!");

// 	puts("\n----- test4 (lonely area case) ------------");
// 	m1 = ft_strdup("11111   ");
// 	m2 = ft_strdup("1N001");
// 	m3 = ft_strdup("10111");
// 	m4 = ft_strdup("10101");
// 	m5 = ft_strdup("11111");
// 	file_lines1[0] = m1;
//     file_lines1[1] = m2;
//     file_lines1[2] = m3;
//     file_lines1[3] = m4;
//     file_lines1[4] = m5;
//     file_lines1[5] = NULL;
// 	assert(validate_walls(file_lines1, &map_data) == STATUS_OK);
// 	puts("Test4 OK!!");
// 	return (0);
// }

/*
	flood fill basic TEST
*/

// t_status	check_iterative_neighbor(const char **file_lines)
// {

// 	return (STATUS_OK);
// }

// int	map[5][5] =
// {
// 	{1, 1, 1, 1, 1},
// 	{1, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 1},
// 	{1, 1, 1, 1, 1}
// };
// const int max_x = 4;
// const int max_y = 4;

// void	flood_fill_basic(int x, int y, char target_color, char new_color)
// {
// 	if (x < 0 || y < 0 || x > max_x || y > max_y)
// 		return ;
// 	if (map[y][x] != target_color || map[y][x] == new_color)
// 		return ;
// 	if (map[y][x] == target_color)
// 		map[y][x] = new_color;
// 	flood_fill_basic(x + 1, y, target_color, new_color);
// 	flood_fill_basic(x - 1, y, target_color, new_color);
// 	flood_fill_basic(x, y + 1, target_color, new_color);
// 	flood_fill_basic(x, y - 1, target_color, new_color);
// }

// #include <stdio.h>
// int	main(void)
// {
// 	const char	target_color = 0;
// 	const char	new_color = 1;
// 	flood_fill_basic(1, 1, target_color, new_color);
// 	for (int i = 0; i < 5; i++) {
// 		for (int j = 0; j < 5; j++) {
// 			printf("%d", map[i][j]);
// 			if (j != 4)
// 				printf(" ");
// 		}
// 		puts("");
// 	}
// 	return (0);
// }
