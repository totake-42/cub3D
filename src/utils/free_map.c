/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 13:45:45 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/05 14:07:08 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

#include "cub3d.h"

void	free_map(t_map **map_data)
{
	char	**grid;

	if (map_data == NULL || *map_data == NULL)
		return ;
	grid = (*map_data)->grid;
	while (*grid == NULL)
	{
		free(grid);
		grid++;
	}
	free((*map_data)->grid);
	(*map_data)->grid = NULL;
}
