/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_input_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:39:53 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/04 18:22:18 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <stdbool.h>
#include "libft.h"
#include "get_next_line.h"

#include "cub3d.h"
#include "status.h"

static t_status	analyze_file_dimensions(
const char *input_file, size_t *col_max_len, size_t *row_len)
{
	int		fd;
	char	*line;
	size_t	line_len;

	fd = open(input_file, STDERR_FILENO);
	if (fd == -1)
	{
		perror(input_file);
		return (STATUS_OK);
	}
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		line_len = ft_strlen(line);
		if (line_len > *col_max_len)
			*col_max_len = line_len;
		free(line);
		(*row_len)++;
	}
	close(fd);
	return (STATUS_OK);
}

static char	**init_map_from_input_file(
const char *input_file, size_t col_max_len)
{
	char	**map_temp;
	char	**map;
	int		fd;
	char	*line;

	map = ft_calloc(sizeof(char *), (col_max_len + 1));
	if (map == NULL)
		return (ft_putendl_fd(ERROR_MALLOC, STDERR_FILENO), NULL);
	fd = open(input_file, O_RDONLY);
	if (fd == -1)
		return (free(map), ft_putendl_fd((char *)input_file, STDERR_FILENO), NULL);
	map_temp = map;
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		*map = line;
		map++;
	}
	close(fd);
	return (map_temp);
}

char	**load_input_file(const char *input_file)
{
	char	**map_temp;
	size_t	col_max_len;
	size_t	row_len;

	if (input_file == NULL)
		return (NULL);
	col_max_len = 0;
	row_len = 0;
	if (analyze_file_dimensions(input_file, &col_max_len, &row_len) \
		== STATUS_ERROR)
		return (NULL);
	map_temp = init_map_from_input_file(input_file, col_max_len);
	if (map_temp == NULL)
		return (NULL);
	return (map_temp);
}

// int	main(void)
// {
// 	const char	*input_file = "test_file";
// 	char		**map = load_input_file(input_file);
// 	if (map == NULL)
// 		puts("map is NULL");
// 	else
// 	{
// 		while (*map != NULL)
// 		{
// 			printf("map: %s\n", *map);
// 			map++;
// 		}
// 	}
// 	return (0);
// }
