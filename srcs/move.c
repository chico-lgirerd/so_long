/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:06:15 by lgirerd           #+#    #+#             */
/*   Updated: 2025/03/03 14:31:22 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

int	clean_exit(t_data *data)
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
	return (0);
}

void	handle_colls(t_data *data, int new_x, int new_y)
{
	data->player.colls++;
	data->map[new_x][new_y] = '0';
}

void	handle_exit(t_data *data)
{
	if (data->player.colls == data->content.found_c)
		clean_exit(data);
}

int	move_player(t_data *data, int dy, int dx, int dir)
{
	int	new_x;
	int	new_y;

	new_x = data->player.x + dx;
	new_y = data->player.y + dy;
	if (new_x < 0 || new_y < 0 || new_x >= data->height || new_x >= data->width)
		return (0);
	if (data->map[new_x][new_y] == '1')
		return (0);
	else if (data->map[new_x][new_y] == 'E')
		handle_exit(data);
	else if (data->map[new_x][new_y] == 'C')
		handle_colls(data, new_x, new_y);
	data->player.x = new_x;
	data->player.y = new_y;
	draw_player(data, dir);
	return (1);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53 || keycode == 65307)
		clean_exit(data);
	else if (keycode == 13 || keycode == 119 || keycode == 65362)
		move_player(data, 0, -1, 1);
	else if (keycode == 1 || keycode == 115 || keycode == 65364)
		move_player(data, 0, 1, 2);
	else if (keycode == 0 || keycode == 97 || keycode == 65361)
		move_player(data, -1, 0, 3);
	else if (keycode == 2 || keycode == 100 || keycode == 65363)
		move_player(data, 1, 0, 4);
	draw_map(data);
	return (0);
}
