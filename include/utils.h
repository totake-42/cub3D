/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:35:22 by itakumi           #+#    #+#             */
/*   Updated: 2026/03/11 20:22:40 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>
# include "cub3d.h"

/* cub3d utils */
void	free_view(t_minilibx **view);
void	exit_cub3d(t_cub3d *cub3d, int exit_status);
void	free_map(t_map **map_data);
void	free_texture(t_cub3d *app);

/* general utils */
void	free_array(void **array);
bool	ft_strequal(const char *s1, const char *s2);
char	*ft_strndup(const char *s, size_t n);
void	print_error(char *context, char *message);
double	get_time(void);

#endif
