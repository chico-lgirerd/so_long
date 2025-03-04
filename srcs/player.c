/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:50:55 by lgirerd           #+#    #+#             */
/*   Updated: 2025/03/04 17:05:04 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	draw_player(t_data *data, int dir)
{
	if (dir == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.up, data->player.width * 64,
			data->player.height * 64);
	else if (dir == 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.right, data->player.width * 64,
			data->player.height * 64);
	else if (dir == 3)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.down, data->player.width * 64,
			data->player.height * 64);
	else if (dir == 4)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.left, data->player.width * 64,
			data->player.height * 64);
}

void	init_player(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y][x] == 'P')
			{
				data->player.height = y;
				data->player.width = x;
			}
			x++;
		}
		y++;
	}
	draw_player(data, 3);
}
