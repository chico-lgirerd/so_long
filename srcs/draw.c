/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:26:29 by lgirerd           #+#    #+#             */
/*   Updated: 2025/03/03 10:37:53 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	draw_wall(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->sprites.wall, x, y);
}

void	draw_space(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->sprites.empty, x, y);
}

void	draw_colls(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->sprites.colls, x, y);
}

void	draw_start_exit(t_data *data, int x, int y, char c)
{
	if (c == 'P')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.start, x, y);
	}
	else if (c == 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.exit, x, y);
	}
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] == '1')
				draw_wall(data, j * 64, i * 64);
			else if (data->map[i][j] == '0')
				draw_space(data, j * 64, i * 64);
			else if (data->map[i][j] == 'C')
				draw_colls(data, j * 64, i * 64);
			else if (data->map[i][j] == 'P' || data->map[i][j] == 'E')
				draw_start_exit(data, j * 64, i * 64, data->map[i][j]);
			j++;
		}
		i++;
	}
	sleep(10);
}
