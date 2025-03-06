/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:19:48 by lgirerd           #+#    #+#             */
/*   Updated: 2025/03/06 17:00:30 by lgirerd          ###   ########lyon.fr   */
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
	if (data->sprites.playerstart)
		mlx_destroy_image(data->mlx_ptr, data->sprites.playerstart);
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
		ft_error(data, "Failed to load player images");
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
	data->sprites.playerstart = mlx_xpm_file_to_image(data->mlx_ptr,
			"img/playerstart.xpm", &width, &height);
	if (!data->sprites.wall || !data->sprites.empty
		|| !data->sprites.colls || !data->sprites.exit || !data->sprites.start
		|| !data->sprites.playerstart)
		ft_error(data, "Failed to load image");
	load_player_images(data);
}
