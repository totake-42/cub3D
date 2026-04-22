/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_only_whitespace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:56:54 by itakumi           #+#    #+#             */
/*   Updated: 2026/04/22 12:56:14 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

bool	ft_is_whitespace(int c)
{
	const char			*whitespace = " ";
	const unsigned char	cc = (unsigned char)c;

	while (*whitespace != '\0')
	{
		if (cc == *whitespace)
			return (true);
		whitespace++;
	}
	return (false);
}
