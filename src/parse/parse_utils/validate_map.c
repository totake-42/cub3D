/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:26:36 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/04 18:34:26 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "status.h"

/*
	CHECK LIST
	1. 
*/
t_status	validate_map(char **map)
{
	if (map == NULL)
		return (STATUS_ERROR);
	while (*map != NULL)	
	{
		
	}
	return (STATUS_OK);
}
