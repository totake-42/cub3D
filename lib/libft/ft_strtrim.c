/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:16:36 by itakumi           #+#    #+#             */
/*   Updated: 2025/05/05 16:36:32 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_trim_char(char c, const char *s1)
{
	while (*s1)
	{
		if (c == *s1)
			return (1);
		s1++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	const char	*start;
	const char	*end;
	char		*trimmed;
	size_t		new_len;

	if (!s1 || !set)
		return (NULL);
	start = s1;
	while (*start && is_trim_char(*start, set))
		start++;
	end = start + ft_strlen(start);
	while (end > start && is_trim_char(*(end - 1), set))
		end--;
	new_len = end - start;
	trimmed = (char *)malloc(new_len + 1);
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, start, new_len + 1);
	return (trimmed);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char *s1 = "  a  suzuki ";
// 	char *set = " ";
// 	char *res = ft_strtrim(s1, set);
// 	printf("%s", res);
// 	return (0);
// }
// 1234491
// 1234567
// 6 - 2 = 4
// 0番目を含めたいなら、＋１する
//
