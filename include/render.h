/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:13:55 by tigarashi         #+#    #+#             */
/*   Updated: 2026/03/12 01:26:59 by tigarashi        ###   ########.fr       */
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

/**
 * @def
 * @brief movement speeds
 */
# define MOVE_SPEED 0.5;
# define ROTATE_SPEED 0.5;

/**
 * @def
 * @brief Minimap color
 */
# define MINIMAP_FLOOR_COLOR 0x00000000
# define MINIMAP_WALL_COLOR 0xFFFFFFFF
# define MINIMAP_DOOR_COLOR 0xFFFFFFFF
# define MINIMAP_PLAYER_COLOR 0x00FF0000

/* render loop */
int		render(void *param);
void	render_minimap(t_cub3d *app);

/* event handler */
int	handle_keypress(int keycode, t_cub3d *app);

/* dda algo */
bool	dda_loop(t_ray *ray, t_cub3d *app);

/* draw line */
void	drawline(t_cub3d *app, t_ray *ray, int x);
void	put_pixel(t_minilibx *view, int x, int y, int color);
void	put_pixel_three_color(t_minilibx *view, int x, int y, int color[static 3]);

/* movement */
void	move_forward(t_cub3d *app);
void	move_backward(t_cub3d *app);
void	move_left(t_cub3d *app);
void	move_right(t_cub3d *app);
void	rotate_left(t_cub3d *app);
void	rotate_right(t_cub3d *app);

/* render utils */
void	init_player(t_player *player, t_map *map_data);
void	init_ray(t_player *player, t_ray *ray, int x, int width);
void	init_sidedist(t_player *player, t_ray *ray);
void	calc_drawline(t_ray *ray, t_cub3d *app);
bool	is_inmap(int map_x, int map_y, t_map *map_data);

/* init player utils */

void	init_player_north(t_player *player);
void	init_player_south(t_player *player);
void	init_player_east(t_player *player);
void	init_player_west(t_player *player);

#endif