/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_input_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:39:53 by itakumi           #+#    #+#             */
/*   Updated: 2026/05/04 18:55:53 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "cub3d.h"
#include "get_next_line_no_nl.h"
#include "libft.h"
#include "status.h"
#include "utils.h"
#include <fcntl.h>
#include <stdbool.h>
#include <sys/types.h>

static t_status	analyze_file_dimensions(const char *input_file,
		size_t *col_max_len, size_t *row_len)
{
	int		fd;
	char	*line;
	size_t	line_len;

	fd = open(input_file, O_RDONLY);
	if (fd == -1)
		return (print_error(NULL, NULL), perror(input_file), STATUS_ERROR);
	while (true)
	{
		line = get_next_line_no_nl(fd);
		if (line == NULL)
		{
			if (errno != 0)
				return (print_error(NULL, NULL), perror(input_file),
					close(fd), STATUS_ERROR);
			break ;
		}
		line_len = ft_strlen(line);
		if (line_len > *col_max_len)
			*col_max_len = line_len;
		free(line);
		(*row_len)++;
	}
	close(fd);
	return (STATUS_OK);
}

static char	**get_file_lines(int fd, size_t row_len, const char *input_file)
{
	char	**file_lines;
	char	**file_lines_temp;
	char	*line;

	file_lines = ft_calloc(sizeof(char *), (row_len + 1));
	if (file_lines == NULL)
		return (print_error(NULL, ERROR_MALLOC), NULL);
	file_lines_temp = file_lines;
	while (true)
	{
		line = get_next_line_no_nl(fd);
		if (line == NULL)
		{
			if (errno != 0)
				return (print_error(NULL, NULL), perror(input_file),
					*file_lines = NULL, free_array((void **)file_lines_temp), NULL);
			break ;
		}
		*file_lines = line;
		file_lines++;
	}
	return (file_lines_temp);
}

static char	**init_file_lines_from_input_file(const char *input_file,
		size_t row_len)
{
	char	**file_lines;
	int		fd;

	fd = open(input_file, O_RDONLY);
	if (fd == -1)
	{
		print_error(NULL, NULL);
		perror(input_file);
		return (NULL);
	}
	file_lines = get_file_lines(fd, row_len, input_file);
	if (file_lines == NULL)
	{
		close(fd);
		return (NULL);
	}
	close(fd);
	return (file_lines);
}

char	**load_input_file(const char *input_file)
{
	char	**file_lines;
	size_t	col_max_len;
	size_t	row_len;

	if (input_file == NULL)
		return (NULL);
	col_max_len = 0;
	row_len = 0;
	if (analyze_file_dimensions(input_file, &col_max_len,
			&row_len) == STATUS_ERROR)
		return (NULL);
	file_lines = init_file_lines_from_input_file(input_file, row_len);
	if (file_lines == NULL)
		return (NULL);
	return (file_lines);
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
