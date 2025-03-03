/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:06:15 by lgirerd           #+#    #+#             */
/*   Updated: 2025/03/03 10:09:17 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53 || keycode == 65307)
		ft_close(data);
	else if (keycode == 13 || keycode == 119 || keycode == 65362) // w ou up
		move_player(data, 0, -1);
	else if (keycode == 1 || keycode == 115 || keycode == 65364) // s ou down
		move_player(data, 0, 1);
	else if (keycode == 0 || keycode == 97 || keycode == 65361) // a ou left
		move_player(data, -1, 0);
	else if (keycode == 2 || keycode == 100 || keycode == 65363) /// d ou right
		move_player(data, 1, 0);
	draw_map(data);
	return (0);
}
