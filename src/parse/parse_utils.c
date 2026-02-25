/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:55:38 by itakumi           #+#    #+#             */
/*   Updated: 2026/02/25 15:11:49 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "cub3d.h"
#include "status.h"
#include "utils.h"

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
