/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:57:11 by itakumi           #+#    #+#             */
/*   Updated: 2025/06/19 16:05:14 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	s1_len = 0;
	while (s1[s1_len])
		s1_len++;
	s2_len = 0;
	while (s2[s2_len])
		s2_len++;
	tmp = ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	while (*s1)
		tmp[i++] = *s1++;
	while (*s2)
		tmp[i++] = *s2++;
	tmp[i] = '\0';
	return (tmp);
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*joined;
// 	size_t	s1_len;
// 	size_t	s2_len;
// 	size_t	i;

// 	s1_len = ft_strlen(s1);
// 	s2_len = ft_strlen(s2);
// 	joined = (char *)malloc(s1_len + s2_len + 1);
// 	if (joined == NULL)
// 		return (NULL);
// 	ft_memmove(joined, s1, s1_len);
// 	i = 0;
// 	while (s2_len > 0 && *s2)
// 	{
// 		joined[s1_len + i] = *s2;
// 		s2_len--;
// 		s2++;
// 		i++;
// 	}
// 	joined[s1_len + i] = '\0';
// 	return (joined);
// }

// #include <stdio.h>
// int main(void)
// {
// 	char *s1 = "fj;osfij";
// 	char *s2 = "fkf'po";
// 	char *res = ft_strjoin(s1, s2);

// 	printf("%s", res);
// 	return (0);
// }
