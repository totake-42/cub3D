/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:54:31 by itakumi           #+#    #+#             */
/*   Updated: 2025/05/05 15:31:49 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tmp;

	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	tmp = malloc(nmemb * size);
	if (tmp == NULL)
		return (NULL);
	ft_memset(tmp, 0, size * nmemb);
	return (tmp);
}

// int	main(void)
// {
// 	#include <stdio.h>
// 	int	nmemb = 0;
// 	int	size =	0;

// 	char *str = ft_calloc(nmemb, size);
// 	printf("%s\n", str);
// 	sprintf(str, "%s %s", "i", "ve");
// 	printf("%s", str);
// 	return (0);
// }
