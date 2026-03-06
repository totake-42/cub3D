/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:38:02 by tigarashi         #+#    #+#             */
/*   Updated: 2026/02/25 15:10:36 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stddef.h>
#include <stdio.h>

/**
 * @fn get_time
 * @brief This function get now time by using gettimeofday.
 * @param nothing
 * @return now time.
 */
double	get_time(void)
{
	struct timeval	tv;
	double	now_time;

	if (gettimeofday(&tv, NULL) == -1)
	{
		perror("gettimeofday");
		return (-1.0);
	}
	now_time = tv.tv_sec + tv.tv_usec * 1e-6;
	return (now_time);
}

// int	main(void)
// {
// 	printf("now: %f\n", get_time());
// 	return (0);
// }