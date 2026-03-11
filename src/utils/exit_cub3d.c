/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:35:02 by itakumi           #+#    #+#             */
/*   Updated: 2026/03/11 20:31:22 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d.h"
#include "utils.h"

// free cub3d structure and exit exit_status
void	exit_cub3d(t_cub3d *cub3d, int exit_status)
{
	if (cub3d == NULL)
		exit(exit_status);
	free_texture(cub3d);
	if (cub3d->view != NULL)
		free_view(&(cub3d->view));
	if (cub3d->map_data != NULL)
		free_map(&(cub3d->map_data));
	exit(exit_status);
}
