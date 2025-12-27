/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 20:47:31 by itakumi           #+#    #+#             */
/*   Updated: 2025/05/04 23:17:34 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			i;
	size_t			j;
	unsigned char	*large;
	unsigned char	*small;

	large = (unsigned char *)big;
	small = (unsigned char *)little;
	if (*small == '\0')
		return ((char *)large);
	i = 0;
	while (large[i] && i < len)
	{
		j = 0;
		while (large[i + j] && small[j] && large[i + j] == small[j]
			&& i + j < len)
			j++;
		if (small[j] == '\0')
			return ((char *)&large[i]);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	big[] = "aaaac";
// 	char	lit[] = "aaac";

// 	int	l = 2;
// #include <stdio.h>
// 	printf("res: %s", ft_strnstr(big, lit, l));
// 	return (0);
// }
// int	main(void)
// {
// 	int	len = 20;
// 	const char *big = "weowlmariolfofspo";
// 	const char *little = "mario";
// 	char *result = ft_strnstr(big, little, len);
// 	printf("%s", result);
// 	return (0);
// }

// int	main(void)
// {
// #include <stdio.h>
// 	int	len = 9999;
// 	const char	*big = "hello world! good night";
// 	const char	*lit = "ht";
// 	char	*res = ft_strnstr(big, lit, len);

// 	printf("res: %s", res);
// 	return (0);
// }
