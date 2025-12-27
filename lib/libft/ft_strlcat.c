/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:15:53 by itakumi           #+#    #+#             */
/*   Updated: 2025/05/05 15:58:58 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_l;
	size_t	src_l;
	size_t	i;

	dst_l = 0;
	src_l = 0;
	while (dst[dst_l] && size > dst_l)
		dst_l++;
	while (src[src_l])
		src_l++;
	i = 0;
	if (size == dst_l)
		return (size + src_l);
	while (src[i] && size > dst_l + i + 1)
	{
		dst[dst_l + i] = src[i];
		i++;
	}
	dst[dst_l + i] = '\0';
	return (dst_l + src_l);
}

// int	main(void)
// {
// 	#include <stdio.h>
// 	char dst[] = "democracy";
// 	char src[10] = "freedom";
// 	int	size = 5;
// 	size_t	result = ft_strlcat(dst, src, size);
// 	printf("%zu", result);
// 	return (0);
// }
