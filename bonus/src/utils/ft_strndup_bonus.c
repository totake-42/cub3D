/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:19:16 by totake            #+#    #+#             */
/*   Updated: 2026/04/22 13:19:18 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*dst;
	char	*dst_temp;

	if (s == NULL)
		return (NULL);
	dst = malloc(sizeof(char) * (n + 1));
	if (dst == NULL)
		return (NULL);
	dst_temp = dst;
	while (*s != '\0' && n-- > 0)
		*dst++ = *s++;
	*dst = '\0';
	return (dst_temp);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	*str = "hello";
// 	char	*res = ft_strndup(str, 10000);
// 	printf("str: %s\n", res);
// 	printf("pointer: %p\n", res);
// 	return (0);
// }
