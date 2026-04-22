/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:18:02 by totake            #+#    #+#             */
/*   Updated: 2026/04/22 13:18:06 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"
#include <stdlib.h>

static void	free_texture_paths(t_map *map_data)
{
	if (map_data->north_tex_path != NULL)
	{
		free(map_data->north_tex_path);
		map_data->north_tex_path = NULL;
	}
	if (map_data->south_tex_path != NULL)
	{
		free(map_data->south_tex_path);
		map_data->south_tex_path = NULL;
	}
	if (map_data->west_tex_path != NULL)
	{
		free(map_data->west_tex_path);
		map_data->west_tex_path = NULL;
	}
	if (map_data->east_tex_path != NULL)
	{
		free(map_data->east_tex_path);
		map_data->east_tex_path = NULL;
	}
}

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
	free_texture_paths(*map_data);
	free(*map_data);
	*map_data = NULL;
}
