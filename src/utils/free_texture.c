/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:27:22 by tigarashi         #+#    #+#             */
/*   Updated: 2026/03/11 20:30:56 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stddef.h>

#include "cub3d.h"

void	free_texture(t_cub3d *app)
{
	int	i;

	if (app == NULL)
		return ;
	i = 0;
	while (i < DIR_COUNT)
	{
		mlx_destroy_image(app->view->mlx_ptr, app->texture[i].img_ptr);
		i++;
	}
}