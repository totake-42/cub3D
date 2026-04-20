/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:35:28 by itakumi           #+#    #+#             */
/*   Updated: 2026/04/20 19:01:15 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	print_error(const char *context, const char *message)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	if (context != NULL)
	{
		ft_putstr_fd((char *)context, STDERR_FILENO);
	}
	if (message != NULL)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd((char *)message, STDERR_FILENO);
	}
}
