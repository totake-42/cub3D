/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:32:11 by itakumi           #+#    #+#             */
/*   Updated: 2026/02/25 13:42:15 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stddef.h>
# include "cub3d.h"
# include "status.h"

/**
 * @def
 * They are parse error macro.
 */
# define ERROR_INVALID_IDENTIFIER "invalid identifier"
# define ERROR_DUPLICATE_IDENTIFIER "redefinition of identifier"
# define ERROR_INVALID_IDENTIFIER_VALUE "invalid identifier value"
# define ERROR_INVALID_COLOR "invalid color"
# define ERROR_NO_ENOUGH_ELEMENTS "not enough elements"

/**
 * @def
 * They are parse grid error messages. 
 */
# define ERROR_TOO_MANY_PLAYERS "Error\n too many players"

/**
 * @def
 * They are Boundary condition number
 */
# define AIRSPACE '0'
# define WALL '1'

/**
 * @def 
 * They are Not found identifier number macro.
 */
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

/* parse grid */
t_status	parse_grid(const char **file_lines, t_map *map_data);
t_status	validate_characters(const char **file_lines);
t_status	validate_player(const char **file_lines, t_map *map_data);
t_status	validate_walls(const char **file_lines, t_map *map_data);

/* parse identifiers */
t_status	parse_identifiers(const char ***file_lines, t_map *map_data);
t_status	set_texture_path(t_map *map_data, size_t offset, const char *value);
t_status	set_layer_color(t_map *map_data, size_t offset, const char *value);

/* parse utils */
char		**duplicate_file_lines(const char **file_lines, int grid_height);

#endif
