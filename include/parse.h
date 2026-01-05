/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:32:11 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/04 18:24:31 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "cub3d.h"
# include "status.h"

/* main */
char	**parse_map(t_cub3d *app, const char *input_file);

/* utils */
char	**load_input_file(const char *input_file);
bool	validate_input_file_extension(const char *input_file);

#endif
