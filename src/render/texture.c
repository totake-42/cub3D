/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:21:11 by tigarashi         #+#    #+#             */
/*   Updated: 2026/03/05 21:36:47 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"

#include "cub3d.h"
#include "status.h"

t_status	set_texture_image(t_cub3d *app)
{
	int	i;

	if (app == NULL)
		return (STATUS_ERROR);
	i = 0;
	while (i < TEXTURE_NUM)
	{
	app->texture[i].img_ptr	= mlx_xpm_file_to_image(app->view->mlx_ptr, );
		if (app->texture[i].img_ptr == NULL)
		{
			while (i > 0)
				mlx_destroy_image(app->view->mlx_ptr, app->texture[i--].img_ptr);
			
			return (STATUS_ERROR);
		}	
	}
	return (STATUS_OK);
}