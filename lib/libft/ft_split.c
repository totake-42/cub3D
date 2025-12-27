/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:02:32 by itakumi           #+#    #+#             */
/*   Updated: 2025/06/24 18:23:59 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*cpy_word(char *str, char c)
{
	int		len;
	int		i;
	char	*cpy;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

static int	words_count(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
	}
	return (count);
}

static void	free_pointer(char **str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		free(str[index]);
		index++;
	}
	free(str);
}

static int	process(char *str, char **new, char c, int i)
{
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
		{
			new[i] = cpy_word(str, c);
			if (!new[i])
				return (0);
			i++;
			while (*str && *str != c)
				str++;
		}
	}
	new[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	char	*str;
	int		size;
	int		i;

	if (!s || *s == '\0')
		return (NULL);
	str = (char *)s;
	size = words_count(str, c);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	i = 0;
	if (process(str, new, c, i) == 0)
	{
		free_pointer(new);
		return (NULL);
	}
	return (new);
}

// int main(void)
// {
// 	int	i = 0;
// 	#include <stdio.h>
//     const char *s = "";
//     char c = ' ';
//     char **result = ft_split(s, c);

//     if (!result)
//         return (1);
// 	printf("[%s]\n", result[i]);
//     while (result[i])
//     {
//         printf("%s\n", *result);
// 		free(result[i]);
//         i++;
//     }
// 	free(result);
//     return (0);
// }
