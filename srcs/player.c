/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:50:55 by lgirerd           #+#    #+#             */
/*   Updated: 2025/03/06 16:57:30 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	draw_player(t_data *data, int dir)
{
	if (data->moves == 0)
		return ;
	if (dir == FRAME_UP)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.up, data->player.width * TILE_SIZE,
			data->player.height * TILE_SIZE);
	else if (dir == FRAME_RIGHT)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.right, data->player.width * TILE_SIZE,
			data->player.height * TILE_SIZE);
	else if (dir == FRAME_DOWN)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.down, data->player.width * TILE_SIZE,
			data->player.height * TILE_SIZE);
	else if (dir == FRAME_LEFT)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.left, data->player.width * TILE_SIZE,
			data->player.height * TILE_SIZE);
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
			if (data->map[y][x] == CHAR_PLAYER)
			{
				data->player.height = y;
				data->player.width = x;
			}
			x++;
		}
		y++;
	}
}
