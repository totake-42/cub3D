/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:32:11 by itakumi           #+#    #+#             */
/*   Updated: 2026/05/04 18:53:00 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "cub3d.h"
# include "status.h"

/* parse identifiers */
# define ERROR_INVALID_IDENTIFIER "Invalid identifier"
# define ERROR_DUPLICATE_IDENTIFIER "Redefinition of identifier"
# define ERROR_EMPTY_TEXTURE_PATH_CONTENT "Texture path is missing"
# define ERROR_INVALID_IDENTIFIER_VALUE "Invalid identifier value"
# define ERROR_INVALID_COLOR "Invalid color"
# define ERROR_NO_ENOUGH_ELEMENTS "Not enough elements"
# define ERROR_MISSING_IDENTIFIERS_BEFORE_MAP "Missing identifiers before map"

/* parse grid*/
/* Error messages */
/* parse player */
# define ERROR_TOO_MANY_PLAYERS "Too many players"
# define ERROR_NO_PLAYER "No player found in the map"
/* parse character */
# define ERROR_INVALID_CHARACTER "Invalid character"
/* parse grid */
# define ERROR_UNCLOSED_MAP "Unclosed map"

/* Boundary condition number*/
# define AIRSPACE '0'
# define WALL '1'

/* Not found identifier number */
# define NOT_FOUND_IDENTIFIER -1

/* Error value */
# define ERROR_VALUE -1
# define RGB_COLOR_LIMIT 255

/* Max grid size */
# define MAX_GRID_SIZE_WIDTH 200
# define MAX_GRID_SIZE_HEIGHT 200
/* parse wall */
# define ERROR_GRID_SIZE "Grid size exceeds the maximum limit of 200"

typedef struct s_element_config
{
	char		*identifier;
	bool		is_set;
	t_status	(*func)(t_map *, size_t, const char *);
	size_t		offset;
}				t_element_config;

/* main */
t_status		parse_map(t_cub3d *app, const char *input_file);

/* utils */
char			**load_input_file(const char *input_file);
bool			validate_input_file_extension(const char *input_file);

/* parse grid */
t_status		parse_grid(const char **file_lines, t_map *map_data);
t_status		validate_characters(const char **file_lines);
t_status		validate_player(const char **file_lines, t_map *map_data);
t_status		validate_walls(const char **file_lines, t_map *map_data);

/* parse identifiers */
t_status		parse_identifiers(const char ***file_lines, t_map *map_data);
t_status		set_texture_path(t_map *map_data, size_t offset,
					const char *value);
t_status		set_layer_color(t_map *map_data, size_t offset,
					const char *value);

/* parse utils */
char			**duplicate_file_lines(const char **file_lines,
					int grid_height);

/* set identifier utils */
bool			is_valid_end_of_strings(const char *str);
int				ft_atoi_only_plus_number(const char *value, size_t n);
size_t			get_color_component_len(const char *value, int color_idx);

/* parse identifier utils */
bool			is_valid_map_line(const char *line);

#endif
