/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:40:44 by itakumi           #+#    #+#             */
/*   Updated: 2025/05/04 23:15:40 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*location;

	i = 0;
	c = (unsigned char)c;
	location = (unsigned char *)s;
	while (i < n)
	{
		if (location[i] == c)
			return (&location[i]);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char *str = "aespa";
// 	char c = 'l';
// 	int n = 4;
// 	char *result = (char *)ft_memchr(str, c, n);
// 	printf("%p\n", str);
// 	printf("%p", result);
// }
