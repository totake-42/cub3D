/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 13:45:45 by itakumi           #+#    #+#             */
/*   Updated: 2026/04/19 11:04:11 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
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
