/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:17:33 by totake            #+#    #+#             */
/*   Updated: 2026/04/22 13:17:34 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_array(void **array)
{
	void	**array_temp;

	if (array == NULL)
		return ;
	array_temp = array;
	while (*array != NULL)
	{
		free(*array);
		*array = NULL;
		array++;
	}
	free(array_temp);
}
