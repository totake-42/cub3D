/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:35:02 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/04 12:51:32 by itakumi          ###   ########.fr       */
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
	if (cub3d->view != NULL)
		free_view(&(cub3d->view));
	exit(exit_status);
}
