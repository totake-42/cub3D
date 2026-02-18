/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_characters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:06:45 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/06 17:57:13 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"

#include "cub3d.h"
#include "status.h"

// space is acceptable
static bool	is_valid_character(int c)
{
	const unsigned char	uc = (const unsigned char)c;

	return (uc == '0' || uc == '1' || uc == 'N' || uc == 'S' || uc == 'E'
		|| uc == 'W' || uc == ' ');
}

t_status	validate_characters(const char **file_lines)
{
	const char	*line;

	while (*file_lines != NULL)
	{
		line = *file_lines;
		while (*line != '\0')
		{
			if (is_valid_character(*line) == false)
				return (STATUS_ERROR);
		}
		file_lines++;
	}
	return (STATUS_OK);
}
