/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:15:31 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/05 16:13:36 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "status.h"
#include "cub3d.h"
#include "utils.h"
#include "parse.h"


// Error 識別子が見つからない
t_status	parse_all(char **file_lines)
{
	if (parse_identifiers(file_lines) == STATUS_ERROR)
		return (STATUS_ERROR);
	if (parse_grid(file_lines) == STATUS_ERROR)
		return (STATUS_ERROR);

	return (STATUS_OK);
}
