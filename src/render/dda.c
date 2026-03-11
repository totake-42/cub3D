/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 16:14:58 by tigarashi         #+#    #+#             */
/*   Updated: 2026/03/12 01:34:28 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "cub3d.h"
#include "render.h"

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
		if (is_inmap((int)ray->map_x, (int)ray->map_y, app->map_data) == false)
			return (false);
		if (app->map_data->grid[(int)ray->map_y][(int)ray->map_x] == '1')
		{
			hit = 1;
			break ;
		}
	}
	if (ray->side == 0)
	{
		if (ray->raydir_x > 0)
			ray->dir = WEST;
		else
			ray->dir = EAST;
		ray->perpwall_dist = (ray->sidedist_x - ray->deltadist_x);
	}
	else
	{
		if (ray->raydir_y > 0)
			ray->dir = SOUTH;
		else
			ray->dir = NORTH;
		ray->perpwall_dist = (ray->sidedist_y - ray->deltadist_y);	
	}
	calc_drawline(ray, app);
	return (true);
}

// 自分のスタート位置はどうしようか。
// static bool	is_ray_hit(t_ray *ray, t_cub3d *app)
// {
// 	return (false);
// }

