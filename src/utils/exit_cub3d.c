/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:35:02 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/04 10:29:29 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d.h"
#include "utils.h"

void	exit_cub3d(t_cub3d *cub3d, int exit_status)
{
	if (cub3d == NULL)	
		exit(exit_status);
	if (cub3d->view != NULL)
		free_view(&(cub3d->view));
	
	// if (cub3d->)
	exit(exit_status);
}
