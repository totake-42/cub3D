/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:35:22 by itakumi           #+#    #+#             */
/*   Updated: 2026/04/17 16:03:18 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"

/* cub3d utils */
void	free_view(t_minilibx **view);
void	free_textures(t_cub3d *app);
void	exit_cub3d(t_cub3d *cub3d, int exit_status);
void	free_map(t_map **map_data);

/* general utils */
void	free_array(void **array);
bool	ft_strequal(const char *s1, const char *s2);
char	*ft_strndup(const char *s, size_t n);
void	print_error(char *context, char *message);
bool	is_whitespace(int c);

#endif
