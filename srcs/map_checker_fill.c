/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_fill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:36:30 by lgirerd           #+#    #+#             */
/*   Updated: 2025/03/03 11:11:56 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i] != NULL)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	free(data);
}

void	free_map_copy(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_copy[i] != NULL)
	{
		free(data->map_copy[i]);
		i++;
	}
	free(data->map_copy);
}

void	flood_fill(t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->height
		|| y >= data->width || data->map_copy[x][y] == '1'
		|| data->map_copy[x][y] == 'X')
		return ;
	if (data->map_copy[x][y] == 'C' || data->map_copy[x][y] == 'E')
	{
		if (data->map_copy[x][y] == 'C')
			data->content.found_c++;
		else if (data->map_copy[x][y] == 'E')
			data->content.found_e++;
		data->map_copy[x][y] = '0';
	}
	data->map_copy[x][y] = 'X';
	flood_fill(data, x - 1, y);
	flood_fill(data, x + 1, y);
	flood_fill(data, x, y - 1);
	flood_fill(data, x, y + 1);
}

int	check_reachable(t_data *data)
{
	data->content.found_c = 0;
	data->content.found_e = 0;
	flood_fill(data, data->player.x, data->player.y);
	return (data->content.found_c == data->content.count_c
		&& data->content.found_e == 1);
}

void	is_map_valid(t_data *data)
{
	init_player_pos(data);
	if (!check_reachable(data))
		ft_map_copy_error(data, "All map elements cannot be reached");
	free_map_copy(data);
}
