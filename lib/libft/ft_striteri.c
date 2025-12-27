/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:59:41 by itakumi           #+#    #+#             */
/*   Updated: 2025/05/05 16:01:50 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void shift(unsigned int shift, char *c)
// {
// 	if (*c == 126)
// 		*c = 34;
// 	else if (*c == 125)
// 		*c = 33;
// 	else if (*c == 124)
// 		*c = 32;
// 	else if (*c == 123)
// 		*c = 31;
// 	else
// 		*c = *c + shift;
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// int	main(void)
// {
// 	#include <stdio.h>
// 	char s[] = "aaaaaaaaa";
// 	void (*f)(unsigned int, char*);
// 	f = shift;
// 	ft_striteri(s, f);
// 	printf("%s", s);
// 	return (0);
// }
