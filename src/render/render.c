/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:24:10 by tigarashi         #+#    #+#             */
/*   Updated: 2026/02/25 15:15:26 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "cub3d.h"
#include "utils.h"

static void	init_variable(double *dir_x, double *dir_y, double *plane_x, double *plane_y);

/**
 * @fn render
 * @brief This function render the player view.
 * @param ( app ) All of the game information.
 * @return Success or failure.
 */
int	render(t_cub3d *app)
{
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	time;
	double	oldtime;

	if (app == NULL)
		return (-1);
	init_variable(&dir_x, &dir_y, &plane_x, &plane_y);
	time = get_time();
	if (time == -1.0)
		return (-1);
	oldtime = time;	
	
	return (0);
}

static void	init_variable(double *dir_x, double *dir_y, double *plane_x, double *plane_y)
{
	*dir_x = -1;
	*dir_y = 0;
	*plane_x = 0;
	*plane_y = 0.66;
}