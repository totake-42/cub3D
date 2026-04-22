/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:35:22 by itakumi           #+#    #+#             */
/*   Updated: 2026/04/21 23:04:01 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include "cub3d_bonus.h"

/* cub3d utils */
void	free_view(t_minilibx **view);
void	free_textures(t_cub3d *app);
void	exit_cub3d(t_cub3d *cub3d, int exit_status);
void	free_map(t_map **map_data);

/* general utils */
void	free_array(void **array);
bool	ft_strequal(const char *s1, const char *s2);
char	*ft_strndup(const char *s, size_t n);
void	print_error(const char *context, const char *message);
bool	is_whitespace(int c);

#endif
