/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_view_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:18:41 by totake            #+#    #+#             */
/*   Updated: 2026/04/22 13:18:50 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>
#include <unistd.h>

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
