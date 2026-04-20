/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifier_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 19:10:20 by itakumi           #+#    #+#             */
/*   Updated: 2026/04/19 19:24:16 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "cub3d.h"
#include "status.h"

bool	is_valid_map_line(const char *line)
{
	const char	*map_characters = "01NSEW ";
	const int	map_characters_len = ft_strlen(map_characters);
	int			i;

	while (*line != '\0')
	{
		i = 0;
		while (map_characters[i] != '\0')
		{
			if (*line == map_characters[i])
			{
				break ;
			}
			i++;
		}
		if (i == map_characters_len)
			return (false);
		line++;
	}
	return (true);
}
