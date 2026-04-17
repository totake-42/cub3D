/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_only_whitespace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:56:54 by itakumi           #+#    #+#             */
/*   Updated: 2026/04/17 16:14:53 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

bool	is_whitespace(int c)
{
	const char			*whitespace = " \t\n";
	unsigned char		cc = (unsigned char)c;
	
	while (*whitespace != '\0')
	{
		if (cc == *whitespace)
			return (true);
		whitespace++;
	}
	return (false);
}
