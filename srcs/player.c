/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:50:55 by lgirerd           #+#    #+#             */
/*   Updated: 2025/03/03 13:55:31 by lgirerd          ###   ########lyon.fr   */
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
