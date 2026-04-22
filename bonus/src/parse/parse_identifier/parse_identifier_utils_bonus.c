/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifier_utils_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:16:17 by totake            #+#    #+#             */
/*   Updated: 2026/04/22 13:16:29 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d_bonus.h"
#include "status_bonus.h"

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
