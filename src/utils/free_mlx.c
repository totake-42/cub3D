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

void	free_mlx_ptr(t_mlx **mlx_ptr)
{
	if (mlx_ptr == NULL || *mlx_ptr == NULL)
		return ;
	if ((*mlx_ptr)->img != NULL)
	{
		mlx_ptr_destroy_image((*mlx_ptr)->mlx, (*mlx_ptr)->img);
		(*mlx_ptr)->img = NULL;
	}
	mlx_loop_end(*mlx_ptr);
	if ((*mlx_ptr)->win != NULL)
	{
		mlx_destroy_window((*mlx_ptr)->mlx, (*mlx_ptr)->win);
		(*mlx_ptr)->win = NULL
	}
	if ((*mlx_ptr)->mlx != NULL)
	{
		mlx_destroy_display((*mlx_ptr)->mlx);
		(*mlx_ptr)->mlx = NULL;
	}
	free(*mlx_ptr);
	*mlx_ptr = NULL;	
}
