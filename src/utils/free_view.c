/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:54:51 by itakumi           #+#    #+#             */
/*   Updated: 2025/12/27 15:27:11 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"

#include "cub3d.h"

void	free_mlx_ptr(t_minilibx **view)
{
	if (view == NULL || *view == NULL)
		return ;
	if ((*view)->img_ptr != NULL)
	{
		mlx_ptr_destroy_image((*view)->mlx_ptr, (*view)->img_ptr);
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
