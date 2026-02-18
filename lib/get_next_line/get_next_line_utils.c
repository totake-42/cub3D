/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 18:01:54 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/04 18:10:11 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	_strlen(char *s)
{
	size_t	l;

	if (!s)
		return (0);
	l = 0;
	while (*s++)
		l++;
	return (l);
}

void	_bzero(char *s, size_t n)
{
	if (!s)
		return ;
	while (n--)
		*s++ = 0;
}

char	*_calloc(size_t nmnb, size_t size)
{
	char	*tmp;

	if (!nmnb || !size)
		return (malloc(0));
	if (SIZE_MAX / nmnb < size)
		return (NULL);
	tmp = (char *)malloc(nmnb * size);
	if (!tmp)
		return (NULL);
	_bzero(tmp, nmnb);
	return (tmp);
}

char	*_strchr(char *s, char c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (*s == c)
		return (s);
	return (NULL);
}

char	*_strjoin(char *s1, char *s2)
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
	tmp = _calloc((s1_len + s2_len + 1), sizeof(char));
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
