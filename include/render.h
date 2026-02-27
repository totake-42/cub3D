/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:13:55 by tigarashi         #+#    #+#             */
/*   Updated: 2026/02/27 19:59:56 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"

/**
 * @def
 * @brief Key codes for X11
 */
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

/* render loop */
int		render(void *param);

/* event handler */
int	handle_keypress(int keycode, t_cub3d *app);

/* dda algo */
bool	dda_loop(t_ray *ray, t_cub3d *app);

/* draw line */
void	drawline(t_cub3d *app, t_ray *ray, int x);
void	put_pixel(t_minilibx *view, int x, int y, int color);

/* movement */
void	move_forward(t_cub3d *app);
void	move_backward(t_cub3d *app);
void	move_left(t_cub3d *app);
void	move_right(t_cub3d *app);
void	rotate_left(t_cub3d *app);
void	rotate_right(t_cub3d *app);

/* render utils */
int		init_player(t_player	*player);
void	init_ray(t_player *player, t_ray *ray, int x, int width);
void	init_sidedist(t_player *player, t_ray *ray);
void	calc_drawline(t_ray *ray, t_cub3d *app);

#endif