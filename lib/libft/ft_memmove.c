/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:37:29 by itakumi           #+#    #+#             */
/*   Updated: 2025/04/30 20:51:51 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (dest == src || n == 0)
		return (dest);
	if (dest < src)
	{
		while (n-- > 0)
			*d++ = *s++;
	}
	else
	{
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	return (dest);
}

// int	main(void)
// {
// 	#include <stdio.h>
// 	int	n = 5;
// 	char whole[20];
// 	for (int i = 0; i < 20; i++)
// 		whole[i] = i + 97;
// 	char *result = ft_memmove(&whole[6], &whole[3], n);
// 	printf("%s\n", result);
// 	return (0);
// }
