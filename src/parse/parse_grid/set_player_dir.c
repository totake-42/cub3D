/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 00:34:43 by tigarashi         #+#    #+#             */
/*   Updated: 2026/03/12 01:42:10 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_north(t_map *map_data)
{
	map_data->player_dir_x = 0;
	map_data->player_dir_y = 1;
}

void	set_player_south(t_map *map_data)
{
	map_data->player_dir_x = 0;
	map_data->player_dir_y = -1;
}

void	set_player_east(t_map *map_data)
{
	map_data->player_dir_x = 1;
	map_data->player_dir_y = 0;
}

void	set_player_west(t_map *map_data)
{
	map_data->player_dir_x = -1;
	map_data->player_dir_y = 0;
}