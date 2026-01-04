/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:33:06 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/04 10:36:22 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"

#include "status.h"
#include "cub3d.h"

t_status	init_view(t_cub3d *cub3d_ptr)
{
	if (cub3d_ptr == NULL)	
		return (STATUS_ERROR);
	cub3d_ptr->view->mlx_ptr = mlx_init();
	if (cub3d_ptr->view->mlx_ptr == NULL)
		return (STATUS_ERROR);
	mlx_get_screen_size(cub3d_ptr->view->mlx_ptr, \
		&(cub3d_ptr->view->win_size_x), &(cub3d_ptr->view->win_size_y));
}
