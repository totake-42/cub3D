/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:53:21 by itakumi           #+#    #+#             */
/*   Updated: 2025/06/19 16:39:34 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

// char	*ft_strchr(const char *s, int c)
// {
// 	unsigned char	v;
// 	unsigned char	*t;

// 	v = (unsigned char)c;
// 	t = (unsigned char *)s;
// 	while (*t)
// 	{
// 		if (*t == v)
// 			return ((char *)t);
// 		t++;
// 	}
// 	if (*t == v)
// 		return ((char *)t);
// 	return (NULL);
// }

// int	main(void)
// {
// 	char c = 'a';
// 	char *s = "cfedgab";
// 	char *p = ft_strchr(s, c);
// 	printf("%p\n", s);
// 	printf("%p", p);
// 	return (0);
// }
