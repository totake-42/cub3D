/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:13:56 by itakumi           #+#    #+#             */
/*   Updated: 2025/05/05 15:48:42 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	t;
	size_t			i;
	unsigned char	*tmp;

	t = (unsigned char)c;
	i = 0;
	tmp = (unsigned char *)s;
	while (i < n)
	{
		tmp[i] = t;
		i++;
	}
	return (tmp);
}

// int	main(void)
// {
// 	int	n = 3;
// 	int	c = 40;
// 	char str[] = "hello world";
// 	char *result = (char *)ft_memset(str, c, n);
// 	printf("%s", result);
// }
