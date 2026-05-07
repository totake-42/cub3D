/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_grid_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 18:32:14 by itakumi           #+#    #+#             */
/*   Updated: 2026/05/07 18:34:14 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	is_player_character(int c)
{
	const unsigned char	uc = (const unsigned char)c;

	return (uc == 'N' || uc == 'S' || uc == 'E' || uc == 'W');
}
