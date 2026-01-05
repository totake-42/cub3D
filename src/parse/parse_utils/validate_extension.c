/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:23:46 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/04 18:24:21 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

static bool	judge_valid(char c, int len)
{
	if (len == 0 && c != 'b')
		return (false);
	else if (len == 1 && c != 'u')
		return (false);
	else if (len == 2 && c != 'c')
		return (false);
	else if (len == 3 && c != '.')
		return (false);
	return (true);
}

// if 3 character from back are '.' 'c' 'u' 'b', the file is acceptable
bool	validate_input_file_extension(const char *input_file)
{
	const char	*last_ptr;
	const char	*start_ptr;
	int			len;

	if (input_file == NULL || *input_file == '\0')
		return (false);
	start_ptr = input_file;
	while (*(input_file + 1) != '\0')
		input_file++;
	last_ptr = input_file;
	len = 0;
	while (last_ptr >= start_ptr && len < 4)
	{
		if (judge_valid(*last_ptr, len) == false)
			return (false);
		last_ptr--;
		len++;
	}
	if (len < 4)
		return (false);
	return (true);
}
