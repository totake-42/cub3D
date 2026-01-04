/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:29:12 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/04 14:31:32 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <stdbool.h>
#include <stdio.h>
#include "libft.h"

#include "cub3d.h"
#include "status.h"

static bool	judge_validate(char c, int len)
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
static bool	validate_input_file(char *input_file)
{
	char	*last_ptr;
	char	*start_ptr;
	int		len;

	if (input_file == NULL || *input_file == '\0')
		return (false);
	start_ptr = input_file;
	while (*(input_file + 1) != '\0')
		input_file++;
	last_ptr = input_file;
	len = 0;
	while (last_ptr >= start_ptr && len < 4)
	{
		if (judge_validate(*last_ptr, len) == false)
			return (false);
		last_ptr--;
		len++;
	}
	if (len < 4)
		return (false);
	return (true);
}

t_status	parse_map(t_cub3d *app, char *input_file)
{
	int	fd;

	if (app == NULL || input_file == NULL)
		return (STATUS_ERROR);
	if (validate_input_file(input_file) == false)
	{
		ft_putendl_fd(ERROR_INVALID_MAP_EXTENSION, STDERR_FILENO);
		return (STATUS_ERROR);
	}
	fd = open(input_file, O_RDONLY);
	if (fd == -1)	
	{
		perror(input_file);
		return (STATUS_ERROR);
	}
	close(fd);
	return (STATUS_OK);
}

// #include <assert.h>
// int	main(void)
// {
// 	char	*test0 = "";
// 	char	*test1 = "cub";
// 	char	*test2 = "b";
// 	char	*test3 = NULL;
// 	char	*test4 = ".cub";
// 	char	*test5 = "..cub";
// 	char	*test6 = "valid.cub";
	
// 	assert(validate_input_file(test0) == false);
// 	assert(validate_input_file(test1) == false);
// 	assert(validate_input_file(test2) == false);
// 	assert(validate_input_file(test3) == false);
// 	assert(validate_input_file(test4) == true);
// 	assert(validate_input_file(test5) == true);
// 	assert(validate_input_file(test6) == true);
// 	return (0);
// }
