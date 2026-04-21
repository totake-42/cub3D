/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:33:06 by itakumi           #+#    #+#             */
/*   Updated: 2026/04/21 17:02:50 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "mlx.h"
#include "status.h"
#include "utils.h"
#include <stdlib.h>

static t_status	set_window(t_minilibx *view)
{
	int	screen_width;
	int	screen_height;

	view->title = "cub3D";
	mlx_get_screen_size(view->mlx_ptr, &screen_width, &screen_height);
	if (screen_width > DEFAULT_WIN_WIDTH && screen_height > DEFAULT_WIN_HEIGHT)
	{
		view->win_width = DEFAULT_WIN_WIDTH;
		view->win_height = DEFAULT_WIN_HEIGHT;
	}
	else
	{
		view->win_width = screen_width;
		view->win_height = screen_height;
	}
	view->win_ptr = mlx_new_window(view->mlx_ptr, view->win_width,
			view->win_height, view->title);
	if (view->win_ptr == NULL)
	{
		print_error(NULL, ERROR_NEW_WINDOW);
		return (STATUS_ERROR);
	}
	return (STATUS_OK);
}

static t_status	set_image(t_minilibx *view)
{
	view->img_ptr = mlx_new_image(view->mlx_ptr, view->win_width,
			view->win_height);
	if (view->img_ptr == NULL)
	{
		print_error(NULL, ERROR_IMAGE);
		return (STATUS_ERROR);
	}
	return (STATUS_OK);
}

static t_status	set_data_addr(t_minilibx *view)
{
	view->data_addr = mlx_get_data_addr(view->img_ptr, &(view->bits_per_pixel),
			&(view->size_line), &(view->endian));
	if (view->data_addr == NULL)
	{
		print_error(NULL, ERROR_DATA_ADDR);
		return (STATUS_ERROR);
	}
	return (STATUS_OK);
}

t_status	init_view(t_cub3d *app)
{
	if (set_window(app->view) == STATUS_ERROR)
	{
		mlx_destroy_display(app->view->mlx_ptr);
		free(app->view->mlx_ptr);
		return (free(app->view), STATUS_ERROR);
	}
	if (set_image(app->view) == STATUS_ERROR)
	{
		mlx_destroy_window(app->view->mlx_ptr, app->view->win_ptr);
		mlx_destroy_display(app->view->mlx_ptr);
		free(app->view);
		return (free(app->view->mlx_ptr), STATUS_ERROR);
	}
	if (set_data_addr(app->view) == STATUS_ERROR)
	{
		mlx_destroy_window(app->view->mlx_ptr, app->view->win_ptr);
		mlx_destroy_image(app->view->mlx_ptr, app->view->img_ptr);
		mlx_destroy_display(app->view->mlx_ptr);
		free(app->view->mlx_ptr);
		return (free(app->view), STATUS_ERROR);
	}
	return (STATUS_OK);
}
