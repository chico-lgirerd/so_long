/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:26:29 by lgirerd           #+#    #+#             */
/*   Updated: 2025/03/05 11:27:59 by lgirerd          ###   ########lyon.fr   */
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
		if (c == 'P')
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->sprites.start, y, x);
		}
		else if (c == 'E')
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
			if (data->map[y][x] == '1')
				draw_wall(data, y * 64, x * 64);
			else if (data->map[y][x] == '0')
				draw_space(data, y * 64, x * 64);
			else if (data->map[y][x] == 'C')
				draw_colls(data, y * 64, x * 64);
			else if (data->map[y][x] == 'P' || data->map[y][x] == 'E')
				draw_start_exit(data, y * 64, x * 64, data->map[y][x]);
			x++;
		}
		y++;
	}
}
