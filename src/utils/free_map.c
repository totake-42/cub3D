/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 13:45:45 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/04 17:58:42 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

#include "cub3d.h"

void	free_map(t_map **map_data)
{
	int	**map;

	if (map_data == NULL || *map_data == NULL)
		return ;
	map = (*map_data)->map;
	while (*map == NULL)
	{
		free(map);
		map++;
	}
	free((*map_data)->map);
	(*map_data)->map = NULL;
}
