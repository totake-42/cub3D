/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:26:36 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/05 14:07:38 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "status.h"

/*
	CHECK LIST
	1. 
*/
t_status	validate_grid(char **file_lines)
{
	if (file_lines == NULL)
		return (STATUS_ERROR);
	while (*file_lines != NULL)	
	{
		
	}
	return (STATUS_OK);
}
