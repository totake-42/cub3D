/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 13:45:45 by itakumi           #+#    #+#             */
/*   Updated: 2026/02/20 12:57:40 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void	free_map(t_map **map_data)
{
	char	**grid;

	if (map_data == NULL || *map_data == NULL)
		return ;
	grid = (*map_data)->grid;
	if (grid != NULL)
	{
		while (*grid != NULL)
		{
			free(*grid);
			grid++;
		}
		free((*map_data)->grid);
		(*map_data)->grid = NULL;
	}
	if ((*map_data)->north_tex_path != NULL)
		free((*map_data)->north_tex_path);
	if ((*map_data)->south_tex_path != NULL)
		free((*map_data)->south_tex_path);
	if ((*map_data)->west_tex_path != NULL)
		free((*map_data)->west_tex_path);
	if ((*map_data)->east_tex_path != NULL)
		free((*map_data)->east_tex_path);
	free(*map_data);
	*map_data = NULL;
}
