/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_characters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:06:45 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/06 14:08:20 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"

#include "cub3d.h"
#include "status.h"

static bool	is_valid_character(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	return (uc == '0' || uc == '1' || uc == 'N' || uc == 'S' || uc == 'E'
		|| uc == 'W');
}

t_status	validate_characters(const char **file_lines)
{
	return (STATUS_OK);
}
