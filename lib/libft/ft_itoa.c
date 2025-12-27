/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:16:25 by itakumi           #+#    #+#             */
/*   Updated: 2025/05/04 23:14:07 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_digit_n(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	count++;
	return (count);
}

char	*ft_itoa(int n)
{
	int		nbr;
	int		count;
	char	*str;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	count = calc_digit_n(n);
	str = (char *)malloc(sizeof(char) * count + 1);
	if (!str)
		return (NULL);
	nbr = n;
	if (n < 0)
		nbr = -n;
	str[count] = '\0';
	count--;
	while (count >= 0)
	{
		str[count] = nbr % 10 + '0';
		nbr /= 10;
		count--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

// #include <limits.h>
// int	main(void)
// {
// 	#include <stdio.h>
// 	int	number = 10;
// 	char* res = ft_itoa(number);
// 	printf("%s", res);
// 	return (0);
// }
