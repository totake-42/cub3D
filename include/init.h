/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 13:39:07 by itakumi           #+#    #+#             */
/*   Updated: 2026/03/11 17:25:49 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "cub3d.h"
# include "status.h"

t_status	init_view(t_cub3d *app);
t_status	set_texture_image(t_cub3d *app);

#endif
