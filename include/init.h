/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 13:39:07 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/04 13:44:18 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "status.h"

t_status	init_map(t_cub3d *app, char *input_file);
t_status	init_view(t_cub3d *app);

#endif
