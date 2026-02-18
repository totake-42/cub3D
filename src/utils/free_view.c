/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 10:38:20 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/04 10:52:58 by itakumi          ###   ########.fr       */
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
	mlx_loop_end(*view);
	if ((*view)->win_ptr != NULL)
	{
		mlx_destroy_window((*view)->mlx_ptr, (*view)->win_ptr);
		(*view)->win_ptr = NULL;
	}
	if ((*view)->mlx_ptr != NULL)
	{
		mlx_destroy_display((*view)->mlx_ptr);
		(*view)->mlx_ptr = NULL;
	}
	free(*view);
	*view = NULL;
}
