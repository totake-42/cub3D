/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_identifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:44:18 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/09 14:39:46 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "cub3d.h"
#include "status.h"
#include "utils.h"
#include "parse.h"

#define ERROR_VALUE -1
#define RGB_COLOR_LIMIT 255

static int	ft_atoi_only_plus_number(const char *value, size_t n)
{
	int	result;

	if (value == NULL)
		return (ERROR_VALUE);
	result = 0;
	while (ft_isdigit(*value) == true && n-- > 0)
	{
		result = 10 * result + (*value - '0');
		if (result > RGB_COLOR_LIMIT)
			return (ERROR_VALUE);
		value++;
	}
	if (n > 0)
		return (ERROR_VALUE);
	return (result);
}

static size_t	find_target_index(const char *hex, char target)
{
	const char	*hex_start;

	hex_start = hex;
	while (*hex != '\0')
	{
		if (*hex == target)
			return (hex - hex_start);
		hex++;
	}
	return (ERROR_VALUE);
}

// number
// validateの役割も持たせるべきだろうか？
// if (*value != '\0' || *value != '\n')
// 	return (STATUS_ERROR);
// それ以降に文字があったら、
t_status	set_layer_color(t_map *map_data, size_t offset, const char *value)
{
	int		len;
	int		*target_ptr;
	int		i;

	target_ptr = (int *)((int *)map_data + offset);
	i = 0;
	while (i < 3)
	{
		if (i == 2)
			len = ft_strlen(value);
		else
			len = find_target_index(value, ',');
		if (len == ERROR_VALUE)
			return (ft_putendl_fd(ERROR_INVALID_COLOR, STDERR_FILENO), \
							STATUS_ERROR);
		target_ptr[i] = ft_atoi_only_plus_number(value, len);
		if (target_ptr[i] == ERROR_VALUE)
		{
			ft_putendl_fd(ERROR_INVALID_COLOR, STDERR_FILENO);
			return (STATUS_ERROR);
		}
		value += len + 1;
		i++;
	}
	return (STATUS_OK);
}

// valueを切り取る
// value ポインタ以降の文字列をすべて受け取るようにする
// ただし、改行は抜く
// FIX ME
t_status	set_texture_path(t_map *map_data, size_t offset, const char *value)
{
	size_t	len;
	char	**target_ptr;

	target_ptr = (char **)((char *)map_data + offset);
	len = 0;
	while (value[len] != '\0')
		len++;
	*target_ptr = ft_strndup(value, len);
	if (*target_ptr == NULL)
		return (STATUS_ERROR);
	return (STATUS_OK);
}
