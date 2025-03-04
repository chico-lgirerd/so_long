/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:19:48 by lgirerd           #+#    #+#             */
/*   Updated: 2025/03/04 14:49:37 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	free_images(t_data *data)
{
	if (data->sprites.empty)
		mlx_destroy_image(data->mlx_ptr, data->sprites.empty);
	if (data->sprites.wall)
		mlx_destroy_image(data->mlx_ptr, data->sprites.wall);
	if (data->sprites.exit)
		mlx_destroy_image(data->mlx_ptr, data->sprites.exit);
	if (data->sprites.colls)
		mlx_destroy_image(data->mlx_ptr, data->sprites.colls);
	if (data->sprites.start)
		mlx_destroy_image(data->mlx_ptr, data->sprites.start);
	if (data->player.up)
		mlx_destroy_image(data->mlx_ptr, data->player.up);
	if (data->player.down)
		mlx_destroy_image(data->mlx_ptr, data->player.down);
	if (data->player.left)
		mlx_destroy_image(data->mlx_ptr, data->player.left);
	if (data->player.right)
		mlx_destroy_image(data->mlx_ptr, data->player.right);
}

void	load_player_images(t_data *data)
{
	int	width;
	int	height;

	data->player.down = mlx_xpm_file_to_image(data->mlx_ptr,
			"img/down.xpm", &width, &height);
	data->player.left = mlx_xpm_file_to_image(data->mlx_ptr,
			"img/left.xpm", &width, &height);
	data->player.right = mlx_xpm_file_to_image(data->mlx_ptr,
			"img/right.xpm", &width, &height);
	data->player.up = mlx_xpm_file_to_image(data->mlx_ptr,
			"img/up.xpm", &width, &height);
	if (!data->player.down || !data->player.left
		|| !data->player.right || !data->player.up)
		clean_error(data, "Failed to load player images");
}

void	load_images(t_data *data)
{
	int	width;
	int	height;

	data->sprites.wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"img/wall.xpm", &width, &height);
	data->sprites.empty = mlx_xpm_file_to_image(data->mlx_ptr,
			"img/empty.xpm", &width, &height);
	data->sprites.colls = mlx_xpm_file_to_image(data->mlx_ptr,
			"img/jerry.xpm", &width, &height);
	data->sprites.exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"img/exit8.xpm", &width, &height);
	data->sprites.start = mlx_xpm_file_to_image(data->mlx_ptr,
			"img/start.xpm", &width, &height);
	if (!data->sprites.wall || !data->sprites.empty
		|| !data->sprites.colls || !data->sprites.exit || !data->sprites.start)
		clean_error(data, "Failed to load image");
	load_player_images(data);
}

void	clean_error(t_data *data, char *msg)
{
	if (data->win_ptr && data->mlx_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
		free_images(data);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	ft_map_error(data, msg);
}

void	init_img_pointers(t_data *data)
{
	data->sprites.empty = NULL;
	data->sprites.wall = NULL;
	data->sprites.colls = NULL;
	data->sprites.exit = NULL;
	data->sprites.start = NULL;
	data->player.up = NULL;
	data->player.down = NULL;
	data->player.right = NULL;
	data->player.left = NULL;
}
