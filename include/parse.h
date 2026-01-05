/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:32:11 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/05 16:12:54 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdbool.h>
# include "cub3d.h"
# include "status.h"

# define ERROR_INVALID_IDENTIFIER "invalid identifier"
# define ERROR_DUPLICATE_IDENTIFIER "redefinition of identifier"

/* Not found identifier number */
# define NOT_FOUND_IDENTIFIER -1

typedef struct s_element_config
{
	char	*identifier;
	bool	is_set;
}	t_element_config;

/* main */
char	**parse_map(t_cub3d *app, const char *input_file);

/* utils */
char		**load_input_file(const char *input_file);
bool		validate_input_file_extension(const char *input_file);
t_status	parse_grid(char **file_lines);
t_status	parse_identifiers(char **file_lines);

#endif
