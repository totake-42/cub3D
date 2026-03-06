/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:21:11 by tigarashi         #+#    #+#             */
/*   Updated: 2026/03/06 13:30:08 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"

#include "cub3d.h"
#include "status.h"

static void	clear_image_ptr(t_cub3d *app, int num)
{
	while (num >= 0)
		mlx_destroy_image(app->view->mlx_ptr, app->texture[num--].img_ptr);
}

t_status	set_texture_image(t_cub3d *app)
{
	int	i;

	if (app == NULL)
		return (STATUS_ERROR);
	i = 0;
	while (i < TEXTURE_NUM)
	{
		app->texture[i].img_ptr	= mlx_xpm_file_to_image(app->view->mlx_ptr, app->map_data->texture_pathes[i], &(app->texture[i].width), &(app->texture[i].height));
		if (app->texture[i].img_ptr == NULL)
		{
			clear_image_ptr(app, i);
			return (STATUS_ERROR);
		}	
		app->texture[i].data_addr = mlx_get_data_addr(app->texture[i].img_ptr, \
			&(app->texture[i].bits_per_pixel), &(app->texture[i].size_line), &(app->texture[i].endian));
		if (app->texture[i].data_addr == NULL)
		{
			clear_image_ptr(app, i);
			return (STATUS_ERROR);
		}
	}
	return (STATUS_OK);
}

// texture imageをつくったら，pathから，texture_npm_to_imageを作る。

// t_status	set_texture_nmp(t_cub3d *app)
// {
// 	int	i;

// 	i = 0;
// 	while (i < DIR_COUNT)
// 	{
// 		mlx_xpm_file_to_image(app->view->mlx_ptr, app->map_data->texture_pathes[i], app->texture[i].width, app->texture[i].height);

// 		i++;
// 	}
// 	return (STATUS_ERROR);
// }