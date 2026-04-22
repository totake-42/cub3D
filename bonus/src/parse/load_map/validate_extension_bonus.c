/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_extension_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:15:24 by totake            #+#    #+#             */
/*   Updated: 2026/04/22 13:15:26 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse_bonus.h"
#include "utils_bonus.h"
#include <stdbool.h>
#include <stddef.h>

bool	validate_input_file_extension(const char *input_file)
{
	size_t	len;
	int		ret;

	if (input_file == NULL)
		return (false);
	len = ft_strlen(input_file);
	if (len < 4)
		return (false);
	ret = ft_strncmp(input_file + len - 4, ".cub", 4);
	if (ret != 0)
	{
		print_error(input_file, ERROR_INVALID_MAP_EXTENSION);
		return (false);
	}
	return (true);
}
