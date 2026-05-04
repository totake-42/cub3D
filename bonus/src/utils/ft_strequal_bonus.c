/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequal_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:19:06 by totake            #+#    #+#             */
/*   Updated: 2026/05/04 19:32:15 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include "libft.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*str1 = (const unsigned char *)s1;
	const unsigned char	*str2 = (const unsigned char *)s2;

	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 != *str2)
		return (*str1 - *str2);
	return (0);
}

bool	ft_strequal(const char *s1, const char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (false);
	return (ft_strcmp(s1, s2));
}
