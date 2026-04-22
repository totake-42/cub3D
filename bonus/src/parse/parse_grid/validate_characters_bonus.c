/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_characters_bonus.c                                      :+:      :+:    :+:   *//*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:06:45 by itakumi           #+#    #+#             */
/*   Updated: 2026/04/21 17:21:58 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"

#include "cub3d_bonus.h"
#include "status_bonus.h"
#include "parse_bonus.h"
#include "utils_bonus.h"

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
	char		invalid_character[2];	

	while (*file_lines != NULL)
	{
		line = *file_lines;
		while (*line != '\0')
		{
			if (is_valid_character(*line) == false)
			{
				invalid_character[0] = *line;
				invalid_character[1] = '\0';
				print_error(invalid_character, ERROR_INVALID_CHARACTER);
				return (STATUS_ERROR);
			}
			line++;
		}
		file_lines++;
	}
	return (STATUS_OK);
}
