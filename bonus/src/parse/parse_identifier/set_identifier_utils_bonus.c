/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_identifier_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:16:59 by totake            #+#    #+#             */
/*   Updated: 2026/04/22 13:17:00 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"

#include "cub3d_bonus.h"
#include "status_bonus.h"
#include "parse_bonus.h"
#include "utils_bonus.h"

int	ft_atoi_only_plus_number(const char *value, size_t n)
{
	int	result;

	if (value == NULL || n == 0)
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

static size_t	len_until_char(const char *hex, char target)
{
	const char	*hex_start;

	hex_start = hex;
	while (*hex != '\0')
	{
		if (*hex == target)
		{
			return (hex - hex_start);
		}
		hex++;
	}
	return (ERROR_VALUE);
}

static size_t	len_until_whitespace(const char *str)
{
	const char	*str_head = str;

	while (*str != '\0' && ft_is_whitespace(*str) == false)
		str++;
	return (str - str_head);
}

size_t	get_color_component_len(const char *value, int color_idx)
{
	size_t	len;

	if (value == NULL)
		return (0);
	if (color_idx == 2)
		len = len_until_whitespace(value);
	else
		len = len_until_char(value, ',');
	return (len);
}

bool	is_valid_end_of_strings(const char *str)
{
	if (str == NULL)
		return (false);
	while (*str != '\0')
	{
		if (ft_is_whitespace(*str) == false)
			return (false);
		str++;
	}
	return (true);
}
