/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:29:33 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/04 18:30:49 by itakumi          ###   ########.fr       */
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
		array++;
	}
	free(array_temp);
}
