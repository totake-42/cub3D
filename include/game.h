/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:00:00 by itakumi           #+#    #+#             */
/*   Updated: 2026/04/01 17:44:14 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "cub3d.h"

// Key codes for X11 (Linux)
// # define KEY_W 119
// # define KEY_A 97
// # define KEY_S 115
// # define KEY_D 100
// # define KEY_ESC 65307
// # define KEY_LEFT 65361
// # define KEY_RIGHT 65363

// Key codes for macOS
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124

// Movement and rotation speeds
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05

// DDA (Digital Differential Analyzer) structure to hold raycasting state
typedef struct s_dda
{
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
}			t_dda;

// game_loop.c
int			game_loop(t_cub3d *app);

// event_handlers.c
int			handle_keypress(int keycode, t_cub3d *app);
int			handle_close(t_cub3d *app);

// render.c
void		render(t_cub3d *app);

// dda.c
void		init_dda(t_dda *dda, t_player *p, double ray_x, double ray_y);
int			run_dda(t_dda *dda, t_map *map);

// draw_column.c
void		calc_draw_info(t_cub3d *app, t_ray_result *ray, t_draw_info *di,
				int tex_idx);
void		draw_textured_column(t_cub3d *app, int x, t_draw_info *di,
				int tex_idx);

// raycasting.c
void		raycast_all(t_cub3d *app);
void		raycast_single(t_cub3d *app);

// movement.c
void		move_forward(t_cub3d *app);
void		move_backward(t_cub3d *app);
void		move_left(t_cub3d *app);
void		move_right(t_cub3d *app);

// rotate.c
void		rotate_left(t_cub3d *app);
void		rotate_right(t_cub3d *app);

#endif
