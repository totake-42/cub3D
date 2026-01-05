/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:26:36 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/05 16:13:33 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "status.h"

/*
	CHECK LIST
	1. 
*/

// is_setがすべて登録されていたら、OK
// 2. gridが閉じられているかどうかを検証する
// (grid の空行は許されない)
t_status	parse_grid(char **file_lines)
{
	if (file_lines == NULL)
		return (STATUS_ERROR);
	while (*file_lines != NULL)	
	{
		
	}
	return (STATUS_OK);
}
