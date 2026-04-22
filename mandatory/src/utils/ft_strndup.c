/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:29:59 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/05 21:30:31 by itakumi          ###   ########.fr       */
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
