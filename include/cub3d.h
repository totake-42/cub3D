/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:18:19 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/06 13:03:40 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>

/* Argument error */
# define ERROR_ARGC "Error\nUsage: ./cub3D <map_file>"

/* window numbers */
# define DEFAULT_WIN_WIDTH 1024
# define DEFAULT_WIN_HEIGHT 768
# define DEBUG_WIN_WIDTH 640
# define DEBUG_WIN_HEIGHT 480

/* Mlx error */
# define ERROR_MLX "Error\ninit mlx failed"

/* Window error */
# define ERROR_NEW_WINDOW "Error\nnew window failed"

/* Image error */
# define ERROR_IMAGE "Error\nnew image failed"

/* Data addr error */
# define ERROR_DATA_ADDR "Error\nget data_addr failed"

/* Map error */
# define ERROR_INVALID_MAP_EXTENSION "Error\ninvalid map extension"

/* Mallox error */
# define ERROR_MALLOC "Error\nmalloc failed"

typedef struct s_minilibx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_width;
	int		win_height;
	char	*title;
	void	*img_ptr;
	char	*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;

}	t_minilibx;

typedef struct s_map
{
	char	*north_tex_path;
	char	*south_tex_path;
	char	*west_tex_path;
	char	*east_tex_path;
	int		floor_color[3];
	int		ceiling_color[3];

	char	**grid;
	int		grid_width;
	int		grid_height;
	int		player_x;
	int		player_y;
	int		player_dir;
}	t_map;

typedef struct s_cub3d
{
	t_minilibx	*view;
	t_map		*map_data;

}	t_cub3d;

#endif
