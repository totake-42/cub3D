/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 01:18:36 by tigarashi         #+#    #+#             */
/*   Updated: 2026/03/12 01:35:10 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player_north(t_player *player)
{
	// 【N】北向きの場合 (Y軸がマイナス方向)
	player->dir_x = 0;
	player->dir_y = -1;
	player->plane_x = -0.66; // X軸に0.66をセット（方向を合わせるためにマイナス）
	player->plane_y = 0;	
}

void	init_player_south(t_player *player)
{
	// 【S】南向きの場合 (Y軸がプラス方向)
	player->dir_x = 0;
	player->dir_y = 1;
	player->plane_x = 0.66; // X軸に0.66をセット
	player->plane_y = 0;
}

void	init_player_east(t_player *player)
{
	// 【E】東向きの場合 (X軸がプラス方向)
	player->dir_x = 1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = -0.66; // Y軸に0.66をセット（西向きと逆）
}

void	init_player_west(t_player *player)
{
	// 【W】西向きの場合 (X軸がマイナス方向) ※元のコード
	player->dir_x = -1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
}

void	init_player(t_player *player1, t_map *map_data)
{
	player1->pos_x = (double)map_data->player_x + 0.5;
	player1->pos_y = (double)map_data->player_y + 0.5;
	if (map_data->player_dir_x == 1)
		init_player_west(player1);
	else if (map_data->player_dir_x == -1)
		init_player_east(player1);
	else if (map_data->player_dir_y == 1)
		init_player_north(player1);
	else
		init_player_south(player1);
}