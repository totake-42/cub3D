/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:23:46 by itakumi           #+#    #+#             */
/*   Updated: 2026/04/20 18:57:33 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "utils.h"
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
		print_error(ERROR_INVALID_MAP_EXTENSION, input_file);
		return (false);
	}
	return (true);
}

// #include <assert.h>
// int	main(void)
// {
// 	const char	*test1 = NULL;
// 	const char	*test2 = "";
// 	const char	*test3 = "abc";
// 	const char	*test4 = "abcd";
// 	const char	*test5 = ".cubb";
// 	const char	*test6 = ".cubb";
// 	const char	*test7 = ".cub";
// 	const char	*test8 = "test.cub";
// 	assert(validate_input_file_extension(test1) == false);
// 	assert(validate_input_file_extension(test2) == false);
// 	assert(validate_input_file_extension(test3) == false);
// 	assert(validate_input_file_extension(test4) == false);
// 	assert(validate_input_file_extension(test5) == false);
// 	assert(validate_input_file_extension(test6) == false);
// 	assert(validate_input_file_extension(test7) == true);
// 	assert(validate_input_file_extension(test8) == true);
// 	return (0);
// }

// static bool	judge_valid(char c, int len)
// {
// 	if (len == 0 && c != 'b')
// 		return (false);
// 	else if (len == 1 && c != 'u')
// 		return (false);
// 	else if (len == 2 && c != 'c')
// 		return (false);
// 	else if (len == 3 && c != '.')
// 		return (false);
// 	return (true);
// }

// // if 3 character from back are '.' 'c' 'u' 'b', the file is acceptable
// bool	validate_input_file_extension(const char *input_file)
// {
// 	const char	*last_ptr;
// 	const char	*start_ptr;
// 	int			len;

// 	if (input_file == NULL || *input_file == '\0')
// 		return (false);
// 	start_ptr = input_file;
// 	while (*(input_file + 1) != '\0')
// 		input_file++;
// 	last_ptr = input_file;
// 	len = 0;
// 	while (last_ptr >= start_ptr && len < 4)
// 	{
// 		if (judge_valid(*last_ptr, len) == false)
// 			return (false);
// 		last_ptr--;
// 		len++;
// 	}
// 	if (len < 4)
// 		return (false);
// 	return (true);
// }
