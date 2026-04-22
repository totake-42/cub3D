/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:35:28 by itakumi           #+#    #+#             */
/*   Updated: 2026/04/21 17:01:15 by itakumi          ###   ########.fr       */
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
