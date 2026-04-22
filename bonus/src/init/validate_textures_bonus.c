/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_textures_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 00:00:00 by totake            #+#    #+#             */
/*   Updated: 2026/04/21 17:56:50 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"
#include "status_bonus.h"
#include <stdbool.h>
#include <stdint.h>
#include <utils_bonus.h>

static bool	check_texture_size_overflow(t_texture *tex)
{
	if (tex->size_line > 0 && (size_t)tex->height > SIZE_MAX
		/ (size_t)tex->size_line)
	{
		print_error(NULL, ERROR_TEXTURE_SIZE_OVERFLOW);
		return (true);
	}
	return (false);
}

static bool	compare_textures_data(t_texture *tex1, t_texture *tex2)
{
	size_t	total_bytes;
	size_t	i;
	char	*data1;
	char	*data2;

	if (tex1->width != tex2->width || tex1->height != tex2->height)
		return (false);
	data1 = tex1->data_addr;
	data2 = tex2->data_addr;
	total_bytes = (size_t)tex1->size_line * (size_t)tex1->height;
	i = 0;
	while (i < total_bytes)
	{
		if (data1[i] != data2[i])
			return (false);
		i++;
	}
	return (true);
}

static const char	*get_texture_name(int index)
{
	if (index == TEX_NORTH)
		return ("North Texture");
	else if (index == TEX_SOUTH)
		return ("South Texture");
	else if (index == TEX_WEST)
		return ("West Texture");
	else
		return ("East Texture");
}

void	print_validate_texture_error(int i, int j)
{
	print_error(NULL, ERROR_TEXTURE_IDENTICAL);
	ft_putstr_fd((char *)get_texture_name(i), 2);
	ft_putstr_fd(" and ", 2);
	ft_putstr_fd((char *)get_texture_name(j), 2);
	ft_putstr_fd("\n", 2);
}

t_status	validate_textures_different(t_texture *textures)
{
	int	i;
	int	j;

	i = 0;
	while (i < TEX_COUNT)
	{
		if (check_texture_size_overflow(&textures[i]))
			return (STATUS_ERROR);
		i++;
	}
	i = 0;
	while (i < TEX_COUNT)
	{
		j = i + 1;
		while (j < TEX_COUNT)
		{
			if (compare_textures_data(&textures[i], &textures[j]))
				return (print_validate_texture_error(i, j), STATUS_ERROR);
			j++;
		}
		i++;
	}
	return (STATUS_OK);
}
