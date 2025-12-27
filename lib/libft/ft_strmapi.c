/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:58:59 by itakumi           #+#    #+#             */
/*   Updated: 2025/05/05 16:01:55 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// char shift(unsigned int shift, char c)
// {

// 	if (c == 126)
// 		return (34);
// 	else if (c == 125)
// 		return (33);
// 	else if (c == 124)
// 		return (32);
// 	else if (c == 123)
// 		return (31);
// 	else
// 		return (c + shift);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (s == NULL || f == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
// {
// 	int a;
// 	a += 1;

// 	aaaa();
// 	f(a,a);
// 	void* p = f;
// 	if (a > 3){
// 		//code
// 	}else{
// 		//code
// 	}

// }

// int	main(void)
// {
// 	#include <stdio.h>
// 	char *s = "override this !";
// 	char (*f)(unsigned int, char);
// 	char *res = ft_strmapi(s, f);
// 	printf("%s", res);
// 	return (0);
// }
