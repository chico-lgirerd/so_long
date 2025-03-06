/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:26:29 by lgirerd           #+#    #+#             */
/*   Updated: 2025/03/06 17:14:21 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	draw_wall(t_data *data, int x, int y)
{
	if (data->mlx_ptr && data->win_ptr && data->sprites.wall)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.wall, y, x);
	}
}

void	draw_space(t_data *data, int x, int y)
{
	if (data->mlx_ptr && data->win_ptr && data->sprites.empty)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.empty, y, x);
	}
}

void	draw_colls(t_data *data, int x, int y)
{
	if (data->mlx_ptr && data->win_ptr && data->sprites.colls)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.colls, y, x);
	}
}

void	draw_start_exit(t_data *data, int x, int y, char c)
{
	if (data->mlx_ptr && data->win_ptr && data->sprites.exit
		&& data->sprites.start)
	{
		if (c == CHAR_PLAYER)
		{
			if (data->moves == 0)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprites.playerstart, y, x);
			else
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprites.start, y, x);
		}
		else if (c == CHAR_EXIT)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->sprites.exit, y, x);
		}
	}
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y][x] == CHAR_WALL)
				draw_wall(data, y * TILE_SIZE, x * TILE_SIZE);
			else if (data->map[y][x] == CHAR_EMPTY)
				draw_space(data, y * TILE_SIZE, x * TILE_SIZE);
			else if (data->map[y][x] == CHAR_COLL)
				draw_colls(data, y * TILE_SIZE, x * TILE_SIZE);
			else if (data->map[y][x] == CHAR_PLAYER
				|| data->map[y][x] == CHAR_EXIT)
				draw_start_exit(data, y * TILE_SIZE,
					x * TILE_SIZE, data->map[y][x]);
			else
				ft_error(data, "Unknown characters in map");
			x++;
		}
		y++;
	}
}
