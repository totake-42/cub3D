/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 12:00:00 by totake            #+#    #+#             */
/*   Updated: 2026/02/22 16:20:55 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>

void	free_textures(t_cub3d *app)
{
	int	i;

	if (app == NULL || app->view == NULL || app->view->mlx_ptr == NULL)
		return ;
	i = 0;
	while (i < TEX_COUNT)
	{
		if (app->textures[i].img_ptr != NULL)
		{
			mlx_destroy_image(app->view->mlx_ptr, app->textures[i].img_ptr);
			app->textures[i].img_ptr = NULL;
		}
		i++;
	}
}
