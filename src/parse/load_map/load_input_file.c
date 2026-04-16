/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_input_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:39:53 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/06 16:56:41 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <stdbool.h>
#include "libft.h"
#include "get_next_line_no_nl.h"

#include "cub3d.h"
#include "status.h"

static t_status	analyze_file_dimensions(
const char *input_file, size_t *col_max_len, size_t *row_len)
{
	int		fd;
	char	*line;
	size_t	line_len;

	fd = open(input_file, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		perror(input_file);
		return (STATUS_ERROR);
	}
	while (true)
	{
		line = get_next_line_no_nl(fd);
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

static char	**init_file_lines_from_input_file(
const char *input_file, size_t row_len)
{
	char	**file_lines;
	char	**file_lines_temp;
	int		fd;
	char	*line;

	file_lines = ft_calloc(sizeof(char *), (row_len + 1));
	if (file_lines == NULL)
		return (ft_putendl_fd(ERROR_MALLOC, STDERR_FILENO), NULL);
	fd = open(input_file, O_RDONLY);
	if (fd == -1)
		return (free(file_lines),
			ft_putendl_fd((char *)input_file, STDERR_FILENO), NULL);
	file_lines_temp = file_lines;
	while (true)
	{
		line = get_next_line_no_nl(fd);
		if (line == NULL)
			break ;
		*file_lines = line;
		file_lines++;
	}
	close(fd);
	return (file_lines_temp);
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
	if (analyze_file_dimensions(input_file, \
		&col_max_len, &row_len) == STATUS_ERROR)
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
