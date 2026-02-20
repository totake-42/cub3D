/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:00:00 by itakumi           #+#    #+#             */
/*   Updated: 2026/02/20 12:42:58 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "cub3d.h"

// game_loop.c
int		game_loop(t_cub3d *app);

// event_handlers.c
int		handle_keypress(int keycode, t_cub3d *app);
int		handle_close(t_cub3d *app);

// render.c
void	render(t_cub3d *app);

#endif
