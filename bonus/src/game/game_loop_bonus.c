/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:13:02 by totake            #+#    #+#             */
/*   Updated: 2026/04/22 13:13:54 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "game_bonus.h"
#include "mlx.h"

/**
 * main game loop function
 * called every frame by mlx_loop_hook
 */
int	game_loop(t_cub3d *app)
{
	render(app);
	mlx_put_image_to_window(app->view->mlx_ptr, app->view->win_ptr,
		app->view->img_ptr, 0, 0);
	return (0);
}
