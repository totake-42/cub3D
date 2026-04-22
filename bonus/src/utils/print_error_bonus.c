/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:19:23 by totake            #+#    #+#             */
/*   Updated: 2026/04/22 13:19:25 by totake           ###   ########.fr       */
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
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (message != NULL)
	{
		ft_putendl_fd((char *)message, STDERR_FILENO);
	}
}
