/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:26:36 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/05 21:32:02 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "status.h"
#include "cub3d.h"

/*
	CHECK LIST
	1. 
*/

// is_setがすべて登録されていたら、OK
// 2. gridが閉じられているかどうかを検証する
// (grid の空行は許されない)
t_status	parse_grid(char **file_lines, t_map *map_data)
{
	if (file_lines == NULL)
		return (STATUS_ERROR);
	(void)map_data;
	while (*file_lines != NULL)
	{
		file_lines++;
	}
	return (STATUS_OK);
}
