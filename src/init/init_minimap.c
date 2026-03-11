/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 22:53:23 by tigarashi         #+#    #+#             */
/*   Updated: 2026/03/11 23:52:19 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "init.h"

void	init_minimap(t_cub3d *app)
{
	if (app == NULL)
		return ;
	app->minimap.height = app->view->win_height / 5;
	app->minimap.width = app->view->win_width / 5;
	app->minimap.tile_size = app->map_data->grid_width;
	app->minimap.offset_height = MINIMAP_OFFSET;
	app->minimap.offset_width = MINIMAP_OFFSET;
	app->minimap.map_center_x = (app->minimap.width + app->minimap.offset_width) / 2;
	app->minimap.map_center_y = (app->minimap.height + app->minimap.offset_height) / 2;
}