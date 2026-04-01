/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 10:38:20 by itakumi           #+#    #+#             */
/*   Updated: 2026/03/30 15:19:49 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>

// free view structure
void	free_view(t_minilibx **view)
{
	if (view == NULL || *view == NULL)
		return ;
	if ((*view)->img_ptr != NULL)
	{
		// mlx_destroy_image((*view)->mlx_ptr, (*view)->img_ptr);
		mlx_destroy_window((*view)->mlx_ptr, (*view)->win_ptr);
		(*view)->img_ptr = NULL;
	}
	if ((*view)->win_ptr != NULL)
	{
		// mlx_destroy_window((*view)->mlx_ptr, (*view)->win_ptr);
		mlx_destroy_window((*view)->mlx_ptr, (*view)->win_ptr);
		(*view)->win_ptr = NULL;
	}
	if ((*view)->mlx_ptr != NULL)
	{
		// mlx_destroy_display((*view)->mlx_ptr);
		// free((*view)->mlx_ptr);
		mlx_destroy_window((*view)->mlx_ptr, (*view)->win_ptr);
		(*view)->mlx_ptr = NULL;
	}
	free(*view);
	*view = NULL;
}
