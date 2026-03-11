/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 22:53:23 by tigarashi         #+#    #+#             */
/*   Updated: 2026/03/11 22:55:58 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_minimap(t_cub3d *app)
{
	if (app == NULL)
		return ;
	app->minimap.height = app->view->win_height / 5;
	app->minimap.width = app->view->win_width;
	app->minimap.tile_size = app->map_data->grid_width;
}