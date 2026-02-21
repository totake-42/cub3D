/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:00:00 by itakumi           #+#    #+#             */
/*   Updated: 2026/02/21 16:39:03 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "cub3d.h"

// Key codes for X11
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

// Movement and rotation speeds
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05

// game_loop.c
int		game_loop(t_cub3d *app);

// event_handlers.c
int		handle_keypress(int keycode, t_cub3d *app);
int		handle_close(t_cub3d *app);

// render.c
void	render(t_cub3d *app);

// raycasting.c
void	raycast_all(t_cub3d *app);
void	raycast_single(t_cub3d *app);

// movement.c
void	move_forward(t_cub3d *app);
void	move_backward(t_cub3d *app);
void	move_left(t_cub3d *app);
void	move_right(t_cub3d *app);
void	rotate_left(t_cub3d *app);
void	rotate_right(t_cub3d *app);

#endif
