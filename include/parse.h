/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:32:11 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/05 21:21:20 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdbool.h>
# include "cub3d.h"
# include "status.h"

# define ERROR_INVALID_IDENTIFIER "invalid identifier"
# define ERROR_DUPLICATE_IDENTIFIER "redefinition of identifier"
# define ERROR_INVALID_IDENTIFIER_VALUE "invalid identifier value"
# define ERROR_INVALID_COLOR "invalid color"
# define ERROR_NO_ENOUGH_ELEMENTS "not enough elements"

/* Not found identifier number */
# define NOT_FOUND_IDENTIFIER -1

typedef struct s_element_config
{
	char		*identifier;
	bool		is_set;
	t_status	(*func)(t_map *, size_t, const char *);
	size_t		offset;
}	t_element_config;

/* main */
t_status	parse_map(t_cub3d *app, const char *input_file);

/* utils */
char		**load_input_file(const char *input_file);
bool		validate_input_file_extension(const char *input_file);
t_status	parse_grid(char **file_lines, t_map *map_data);
t_status	parse_identifiers(char **file_lines, t_map *map_data);
t_status	set_texture_path(t_map *map_data, size_t offset, const char *value);
t_status	set_layer_color(t_map *map_data, size_t offset, const char *value);

#endif
