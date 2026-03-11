/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 16:14:58 by tigarashi         #+#    #+#             */
/*   Updated: 2026/03/11 16:40:34 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "cub3d.h"
#include "render.h"

static bool	is_inmap(t_ray *ray, t_map *map_data);

bool	dda_loop(t_ray *ray, t_cub3d *app)
{
	int	hit;

	hit = 0;
	while (hit == 0)	
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}

		// map が外に出ているかどうかを判定する関数が欲しい。
		if (is_inmap(ray, app->map_data) == false)
			return (false);
		if (app->map_data->grid[(int)ray->map_y][(int)ray->map_x] == '1')
		{
			hit = 1;
			break ;
		}
	}
	if (ray->side == 0)
		ray->perpwall_dist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->perpwall_dist = (ray->sidedist_y - ray->deltadist_y);	
	calc_drawline(ray, app);
	return (true);
}

/**
 * @fn is_inmap
 * @brief This function check whether the ray is in the map.
 * @param ( ray ) ray struct
 * @return True or false.
 */
static bool	is_inmap(t_ray *ray, t_map *map_data)
{
	int	map_x;
	int	map_y;
	int	row_len;

	map_x = (int)ray->map_x;
	map_y = (int)ray->map_y;
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

// 自分のスタート位置はどうしようか。
// static bool	is_ray_hit(t_ray *ray, t_cub3d *app)
// {
// 	return (false);
// }

