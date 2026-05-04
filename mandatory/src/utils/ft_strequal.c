/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:43:00 by itakumi           #+#    #+#             */
/*   Updated: 2026/05/04 20:37:42 by tigarashi        ###   ########.fr       */
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
	if (ft_strcmp(s1, s2) == 0)
		return (true);
	return (false);
}
