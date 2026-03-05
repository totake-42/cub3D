/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:24:10 by tigarashi         #+#    #+#             */
/*   Updated: 2026/03/05 18:49:55 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stddef.h>
#include <math.h>
#include "libft.h"

#include "cub3d.h"
#include "status.h"
#include "render.h"
#include "utils.h"

static t_status	render_loop(t_cub3d *app);
static	void	pixel_loop(t_cub3d *app);

/**
 * @fn render
 * @brief This function render the player view.
 * @param ( app ) All of the game information.
 * @return Success or failure.
 */
int	render(void *param)
{
	t_cub3d		*app;

	if (param == NULL)
		return (-1);
	app = (t_cub3d *)param;
	if (render_loop(app) == STATUS_ERROR)
		return (-1);
	return (0);
}

static t_status	render_loop(t_cub3d *app)
{
	mlx_clear_window(app->view->mlx_ptr, app->view->win_ptr);
	ft_bzero(app->view->data_addr, app->view->size_line * app->view->win_height);
	pixel_loop(app);	
	// put_image
	mlx_put_image_to_window(app->view->mlx_ptr, app->view->win_ptr, app->view->img_ptr, 0, 0);
	return (STATUS_OK);
}

static	void	pixel_loop(t_cub3d *app)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < app->view->win_width)
	{
		init_ray(&(app->player), &ray, x, app->view->win_width);
		init_sidedist(&(app->player), &ray);
		// calculate perp wall distance
		if (dda_loop(&ray, app) == true)
		{
			calc_drawline(&ray, app);
			// 一旦色は白のみにする
			ray.wall_color = 0xFFFFFF;
		}
		else
		{
			ray.wall_color = 0x000000;	
		}
		drawline(app, &ray, x);
			// colorを黑にする。
		// x = ?の線を引く。
		x++;
	}
	
}