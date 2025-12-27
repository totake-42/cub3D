/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:10:34 by itakumi           #+#    #+#             */
/*   Updated: 2025/05/04 23:17:42 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*v;
	unsigned char	t;
	char			*last;

	v = (unsigned char *)s;
	t = (unsigned char)c;
	last = NULL;
	while (*v)
	{
		if (*v == t)
			last = (char *)v;
		v++;
	}
	if (*v == t)
		return ((char *)v);
	return (last);
}

// int	main(void)
// {
// 	#include <stdio.h>
// 	char c = 'a';
// 	const char *s = "booboonebou";
// 	char *res = ft_strrchr(s, c);

// 	printf("%s", res);
// 	return (0);
// }
