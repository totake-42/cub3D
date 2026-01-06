/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:55:38 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/06 18:56:01 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "cub3d.h"
#include "status.h"

char	**duplicate_file_lines(const char **file_lines, int grid_height)
{
	char	**file_lines_cpy;
	char	**tmp;

	file_lines_cpy = ft_calloc(sizeof(char *), (grid_height + 1));
	if (file_lines_cpy == NULL)
	{
		ft_putendl_fd(ERROR_MALLOC, STDERR_FILENO);
		return (NULL);
	}
	tmp = file_lines_cpy;
	while (*file_lines != NULL)
	{
		*file_lines_cpy = ft_strdup(*file_lines);
		if (*file_lines_cpy == NULL)
		{
			free_array((void **)tmp);
			return (NULL);
		}
		file_lines_cpy++;
		file_lines++;
	}
	return (tmp);
}
