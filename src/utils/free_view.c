/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 10:38:20 by itakumi           #+#    #+#             */
/*   Updated: 2026/03/11 20:24:57 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>

#include "cub3d.h"

// free view structure 
void	free_view(t_minilibx **view)
{
	if (view == NULL || *view == NULL)
		return ;
	if ((*view)->img_ptr != NULL)
	{
		mlx_destroy_image((*view)->mlx_ptr, (*view)->img_ptr);
		(*view)->img_ptr = NULL;
	}
	mlx_loop_end((*view)->mlx_ptr);
	if ((*view)->win_ptr != NULL)
	{
		mlx_destroy_window((*view)->mlx_ptr, (*view)->win_ptr);
		(*view)->win_ptr = NULL;
	}
	if ((*view)->mlx_ptr != NULL)
	{
		mlx_destroy_display((*view)->mlx_ptr);
		free((*view)->mlx_ptr);
		(*view)->mlx_ptr = NULL;
	}
	free(*view);
	*view = NULL;
}
