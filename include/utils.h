/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:35:22 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/05 19:58:52 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>
# include "cub3d.h"

/* cub3d utils */
void	free_view(t_minilibx **view);
void	exit_cub3d(t_cub3d *cub3d, int exit_status);
void	free_map(t_map **map_data);

/* general utils */
void	free_array(void **array);
bool	ft_strequal(const char *s1, const char *s2);
char	*ft_strndup(const char *s, size_t n);
void	print_error(char *context, char *message);

#endif
