/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 13:34:15 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/04 13:48:33 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include "libft.h"

#include "cub3d.h"
#include "status.h"

t_status	init_map(t_cub3d *app, char *input_file)
{
	int	fd;

	if (app == NULL || input_file == NULL)
		return (STATUS_ERROR);
	fd = open(input_file, O_RDONLY);
	if (fd == -1)	
	{
		perror(input_file);
		return (STATUS_ERROR);
	}
	
	return (STATUS_OK);
}
