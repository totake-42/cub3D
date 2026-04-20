/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 12:00:00 by totake            #+#    #+#             */
/*   Updated: 2026/04/20 15:14:55 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "mlx.h"
#include "status.h"
#include "utils.h"

static t_status	load_single_texture(void *mlx_ptr, t_texture *tex, char *path)
{
	tex->img_ptr = mlx_xpm_file_to_image(mlx_ptr, path, &tex->width,
			&tex->height);
	if (tex->img_ptr == NULL)
	{
		print_error(ERROR_TEXTURE, path);
		return (STATUS_ERROR);
	}
	tex->data_addr = mlx_get_data_addr(tex->img_ptr, &tex->bits_per_pixel,
			&tex->size_line, &tex->endian);
	if (tex->data_addr == NULL)
	{
		ft_putendl_fd(ERROR_DATA_ADDR, STDERR_FILENO);
		mlx_destroy_image(mlx_ptr, tex->img_ptr);
		tex->img_ptr = NULL;
		return (STATUS_ERROR);
	}
	return (STATUS_OK);
}

static void	free_loaded_textures(void *mlx_ptr, t_texture *textures, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (textures[i].img_ptr != NULL)
		{
			mlx_destroy_image(mlx_ptr, textures[i].img_ptr);
			textures[i].img_ptr = NULL;
		}
		i++;
	}
}

static char	*get_texture_path(t_map *map_data, int index)
{
	if (index == TEX_NORTH)
		return (map_data->north_tex_path);
	else if (index == TEX_SOUTH)
		return (map_data->south_tex_path);
	else if (index == TEX_WEST)
		return (map_data->west_tex_path);
	else
		return (map_data->east_tex_path);
}

t_status	init_textures(t_cub3d *app)
{
	int		i;
	char	*path;

	i = 0;
	while (i < TEX_COUNT)
	{
		app->textures[i].img_ptr = NULL;
		i++;
	}
	i = 0;
	while (i < TEX_COUNT)
	{
		path = get_texture_path(app->map_data, i);
		if (load_single_texture(app->view->mlx_ptr, &app->textures[i],
				path) == STATUS_ERROR)
		{
			free_loaded_textures(app->view->mlx_ptr, app->textures, i);
			return (STATUS_ERROR);
		}
		i++;
	}
	return (STATUS_OK);
}
