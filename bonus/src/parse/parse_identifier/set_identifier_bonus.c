/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_identifier_bonus.c                                           :+:      :+:    :+:   *//*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:44:18 by itakumi           #+#    #+#             */
/*   Updated: 2026/04/21 17:58:43 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "parse_bonus.h"
#include "status_bonus.h"
#include "utils_bonus.h"

t_status	set_layer_color(t_map *map_data, size_t offset, const char *value)
{
	int			len;
	int			*target_ptr;
	int			color_idx;
	const char	*value_head = value;

	target_ptr = (int *)((char *)map_data + offset);
	color_idx = 0;
	while (color_idx < 3)
	{
		len = get_color_component_len(value, color_idx);
		if (len == ERROR_VALUE)
			return (print_error(value_head, ERROR_INVALID_COLOR), STATUS_ERROR);
		target_ptr[color_idx] = ft_atoi_only_plus_number(value, len);
		if (target_ptr[color_idx] == ERROR_VALUE)
			return (print_error(value_head, ERROR_INVALID_COLOR), STATUS_ERROR);
		value += len + 1;
		color_idx++;
	}
	if (is_valid_end_of_strings(value) == false)
		return (print_error(value_head, ERROR_INVALID_COLOR), STATUS_ERROR);
	return (STATUS_OK);
}

t_status	set_texture_path(t_map *map_data, size_t offset, const char *value)
{
	size_t	len;
	char	**target_ptr;

	target_ptr = (char **)((char *)map_data + offset);
	len = 0;
	while (value[len] && ft_is_whitespace(value[len]) == false)
		len++;
	*target_ptr = ft_strndup(value, len);
	if (*target_ptr == NULL)
		return (STATUS_ERROR);
	value += len;
	while (*value)
	{
		if (ft_is_whitespace(*value) == false)
		{
			print_error(value, ERROR_INVALID_IDENTIFIER_VALUE);
			free(*target_ptr);
			*target_ptr = NULL;
			return (STATUS_ERROR);
		}
		value++;
	}
	return (STATUS_OK);
}
