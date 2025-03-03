/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:50:55 by lgirerd           #+#    #+#             */
/*   Updated: 2025/03/03 14:18:06 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	draw_player(t_data *data, int dir)
{
	if (dir == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.up, data->player.x, data->player.y);
	else if (dir == 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.right, data->player.x, data->player.y);
	else if (dir == 3)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.down, data->player.x, data->player.y);
	else if (dir == 4)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.left, data->player.x, data->player.y);
}

void	init_player(t_data *data)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] == 'P')
			{
				data->player.x = i;
				data->player.y = j;
			}
			j++;
		}
		i++;
	}
	draw_player(data, 3);
}
