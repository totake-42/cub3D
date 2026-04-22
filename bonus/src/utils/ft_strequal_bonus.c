/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequal_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:19:06 by totake            #+#    #+#             */
/*   Updated: 2026/04/22 13:19:09 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include "libft.h"

bool	ft_strequal(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;	

	if (s1 == NULL || s2 == NULL)
		return (false);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1_len == s2_len && ft_strncmp(s1, s2, s1_len) == 0)
		return (true);
	return (false);
}
