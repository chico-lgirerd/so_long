/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_fill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:36:30 by lgirerd           #+#    #+#             */
/*   Updated: 2025/03/12 15:15:19 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_data *data)
{
	int	y;

	y = 0;
	while (data->map[y] != NULL)
	{
		free(data->map[y]);
		y++;
	}
	free(data->map);
	data->map = NULL;
}

void	free_map_copy(t_data *data)
{
	int	y;

	y = 0;
	while (data->map_copy[y] != NULL)
	{
		free(data->map_copy[y]);
		y++;
	}
	free(data->map_copy);
	data->map_copy = NULL;
}

void	flood_fill(t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || y >= data->height
		|| x >= data->width || data->map_copy[y][x] == CHAR_WALL
		|| data->map_copy[y][x] == 'X')
		return ;
	if (data->map_copy[y][x] == CHAR_COLL || data->map_copy[y][x] == CHAR_EXIT)
	{
		if (data->map_copy[y][x] == CHAR_COLL)
			data->content.found_c++;
		else if (data->map_copy[y][x] == CHAR_EXIT)
			data->content.found_e++;
		data->map_copy[y][x] = CHAR_EMPTY;
	}
	data->map_copy[y][x] = 'X';
	flood_fill(data, x - 1, y);
	flood_fill(data, x + 1, y);
	flood_fill(data, x, y - 1);
	flood_fill(data, x, y + 1);
}

int	check_reachable(t_data *data)
{
	data->content.found_c = 0;
	data->content.found_e = 0;
	flood_fill(data, data->player.width, data->player.height);
	return (data->content.found_c == data->content.count_c
		&& data->content.found_e == 1);
}

void	is_map_valid(t_data *data)
{
	init_player_pos(data);
	if (!check_reachable(data))
		ft_error(data, "All map elements cannot be reached");
	free_map_copy(data);
}
