/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 13:39:07 by itakumi           #+#    #+#             */
/*   Updated: 2026/04/21 23:04:01 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_BONUS_H
# define INIT_BONUS_H

# include "status_bonus.h"

t_status	init_view(t_cub3d *app);
t_status	init_textures(t_cub3d *app);
void		init_player(t_cub3d *app);
t_status	validate_textures_different(t_texture *textures);

#endif
