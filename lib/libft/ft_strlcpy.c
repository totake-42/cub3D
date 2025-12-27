/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:53:47 by itakumi           #+#    #+#             */
/*   Updated: 2025/06/24 14:38:07 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_l;

	i = 0;
	src_l = 0;
	if (dst == NULL || src == NULL || *src == '\0')
		return (src_l);
	while (src[src_l])
		src_l++;
	if (size == 0)
		return (src_l);
	while (i + 1 < size && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_l);
}

// int	main(void)
// {
// 	char dst[] = "vctoria";
// 	char *src = "tnaito";
// 	int	size = 0;
// 	size_t result1 = ft_strlcpy(dst, src, size);
// 	// size_t result2 = strlcpy(dst, src, size);
// 	printf("result1 : %zu ", result1);
// 	printf("%s", dst);
// 	// printf("result : %zu %s", result2, dst);
// 	return (0);
// }
