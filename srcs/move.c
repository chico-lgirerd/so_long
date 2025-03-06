/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:06:15 by lgirerd           #+#    #+#             */
/*   Updated: 2025/03/06 17:41:58 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"

int	clean_exit(t_data *data)
{
	if (data->map)
		free_map(data);
	if (data->map_copy)
		free_map_copy(data);
	free_images(data);
	if (data->win_ptr && data->mlx_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	if (data)
		free(data);
	exit(0);
	return (0);
}

void	handle_colls(t_data *data, int new_y, int new_x)
{
	data->player.colls++;
	data->map[new_y][new_x] = CHAR_EMPTY;
}

void	handle_exit(t_data *data)
{
	if (data->player.colls == data->content.found_c)
		clean_exit(data);
}

int	move_player(t_data *data, int dx, int dy, int dir)
{
	int			new_x;
	int			new_y;

	new_x = data->player.width + dx;
	new_y = data->player.height + dy;
	if (new_x < 0 || new_y < 0 || new_y >= data->height || new_x >= data->width)
		return (0);
	if (data->map[new_y][new_x] == CHAR_WALL)
		return (0);
	else if (data->map[new_y][new_x] == CHAR_EXIT)
		handle_exit(data);
	else if (data->map[new_y][new_x] == CHAR_COLL)
		handle_colls(data, new_y, new_x);
	data->player.height = new_y;
	data->player.width = new_x;
	if (data->mlx_ptr && data->win_ptr)
	{
		ft_printf("Moves : %d\n", data->moves);
		data->moves++;
		draw_map(data);
		draw_player(data, dir);
	}
	return (1);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53 || keycode == 65307)
		clean_exit(data);
	else if (keycode == 13 || keycode == 119 || keycode == 65362)
		move_player(data, 0, -1, FRAME_UP);
	else if (keycode == 1 || keycode == 115 || keycode == 65364)
		move_player(data, 0, 1, FRAME_DOWN);
	else if (keycode == 0 || keycode == 97 || keycode == 65361)
		move_player(data, -1, 0, FRAME_LEFT);
	else if (keycode == 2 || keycode == 100 || keycode == 65363)
		move_player(data, 1, 0, FRAME_RIGHT);
	return (0);
}
