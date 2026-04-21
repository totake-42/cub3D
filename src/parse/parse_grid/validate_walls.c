/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:10:33 by itakumi           #+#    #+#             */
/*   Updated: 2026/04/21 21:20:11 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "parse.h"
#include "status.h"
#include "utils.h"

static t_status	flood_fill(char **file_lines, int x_pos, int y_pos,
		t_map const *map_data)
{
	if (y_pos < 0 || y_pos >= map_data->grid_height)
		return (STATUS_ERROR);
	if (x_pos < 0 || x_pos >= (int)ft_strlen(file_lines[y_pos]))
		return (STATUS_ERROR);
	if (file_lines[y_pos][x_pos] == '\0' || file_lines[y_pos][x_pos] == ' ')
		return (STATUS_ERROR);
	if (file_lines[y_pos][x_pos] == WALL)
		return (STATUS_OK);
	file_lines[y_pos][x_pos] = WALL;
	if (flood_fill(file_lines, x_pos + 1, y_pos, map_data) == STATUS_ERROR)
		return (STATUS_ERROR);
	if (flood_fill(file_lines, x_pos - 1, y_pos, map_data) == STATUS_ERROR)
		return (STATUS_ERROR);
	if (flood_fill(file_lines, x_pos, y_pos + 1, map_data) == STATUS_ERROR)
		return (STATUS_ERROR);
	if (flood_fill(file_lines, x_pos, y_pos - 1, map_data) == STATUS_ERROR)
		return (STATUS_ERROR);
	return (STATUS_OK);
}

//  ひせいじょうもじれつはべかんすうのせきむ
static t_status	check_4_direction(const char **file_lines, int x, int y) 
{
	// x - 1, x + 1, y - 1, y + 1 がはんいがいかどうかしらべる
	if (x <= 0 || file_lines[y][x + 1] == '\0' || y <= 0 || file_lines[y + 1] == NULL)
		return (STATUS_ERROR);
	if (file_lines[y][x - 1] == ' ' || file_lines[y][x + 1] == ' ')
		return (STATUS_ERROR);
	if ((size_t)x >= ft_strlen(file_lines[y - 1]) || (size_t)x >= ft_strlen(file_lines[y + 1]))
		return (STATUS_ERROR);
	if (file_lines[y - 1][x] == ' ' || file_lines[y + 1][x] == ' ')
		return (STATUS_ERROR);
	return (STATUS_OK);
}

/**
 * @fn validate_all_walls
 * @param (file_lines) @param (map_data)
 * @brief validate all '0' for 4 direction.
 */
static t_status	validate_all_walls(const char **file_lines)
{
	int		x;
	int		y;

	y = 0;
	while (file_lines[y] != NULL)	
	{
		x = 0;
		while (file_lines[y][x] != '\0') // 
		{
			if (file_lines[y][x] != '0')
			{
				// check 4 direction.
				x++;
				continue ;
			}
			if (check_4_direction(file_lines, x, y) == STATUS_ERROR)
			{
				print_error(NULL, ERROR_NO_SURROUNDED_WALL);
				return (STATUS_ERROR);
			}
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
	if (validate_all_walls((const char **)file_lines_cpy) == STATUS_ERROR)
	{
		free_array((void **)file_lines_cpy);
		return (STATUS_ERROR);
	}
	if (flood_fill(file_lines_cpy, map_data->player_x, map_data->player_y,
			(t_map const *)map_data) == STATUS_ERROR)
	{
		free_array((void **)file_lines_cpy);
		print_error(NULL, ERROR_NO_SURROUNDED_WALL);
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
