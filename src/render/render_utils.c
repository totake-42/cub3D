/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 16:03:18 by tigarashi         #+#    #+#             */
/*   Updated: 2026/03/11 23:31:17 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"

#include "cub3d.h" 
#include "status.h"

int	init_player(t_player *player1, t_map *map_data)
{
	player1->pos_x = (double)map_data->player_x + 0.5;
	player1->pos_y = (double)map_data->player_y + 0.5;
	player1->dir_x = -1;
	player1->dir_y = 0;
	player1->plane_x = 0;
	player1->plane_y = 0.66;
	return (STATUS_OK);
}

void	init_ray(t_player *player, t_ray *ray, int x, int width)
{
	// calculater raydir vector
	ray->camera_x = 2 * x / (double)width - 1;
	ray->raydir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->raydir_y = player->dir_y + player->plane_y * ray->camera_x;

	// set start position and now position.
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;

	if (ray->raydir_x == 0)
		ray->deltadist_x = 1e30;
	else
		ray->deltadist_x = 1 / fabs(ray->raydir_x);
	if (ray->raydir_y == 0)	
		ray->deltadist_y = 1e30;
	else
		ray->deltadist_y = 1 / fabs(ray->raydir_y);
}

void	init_sidedist(t_player *player, t_ray *ray)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (player->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - player->pos_x) * ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (player->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - player->pos_y) * ray->deltadist_y;
	}
}

void	calc_drawline(t_ray *ray, t_cub3d *app)
{
	ray->line_height = (int)(app->view->win_height / ray->perpwall_dist);
	ray->draw_start = -ray->line_height / 2 + app->view->win_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + app->view->win_height / 2;
	if (ray->draw_end >= app->view->win_height)
		ray->draw_end = app->view->win_height - 1;	
}

/**
 * @fn is_inmap
 * @brief This function check whether the ray is in the map.
 * @param ( ray ) ray struct
 * @return True or false.
 */
bool	is_inmap(int map_x, int map_y, t_map *map_data)
{
	int	row_len;

	// y axis check
	if (map_y < 0 || map_y >= map_data->grid_height)
		return (false);
	// x axis minus check
	if (map_x < 0)
		return (false);
	row_len = ft_strlen(map_data->grid[map_y]);
	// x axis len check
	if (map_x >= row_len)
		return (false);
	// null character check
	if (map_data->grid[map_y][map_x] == '\0')
		return (false);
	return (true);
}