/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 13:45:45 by itakumi           #+#    #+#             */
/*   Updated: 2026/02/25 15:19:29 by tigarashi        ###   ########.fr       */
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
	while (*grid != NULL)
	{
		free(*grid);
		grid++;
	}
	free((*map_data)->grid);
	(*map_data)->grid = NULL;
}
