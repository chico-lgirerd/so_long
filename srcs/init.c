/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:16:54 by lgirerd           #+#    #+#             */
/*   Updated: 2025/03/03 09:52:17 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

char	**init_map_copy(t_data *data)
{
	int		i;
	int		j;
	char	**map_copy;

	map_copy = malloc(sizeof(char *) * (data->height + 1));
	if (!map_copy)
		ft_map_error(data, "Failed to allocate memory : map_copy");
	i = 0;
	while (i < data->height)
	{
		map_copy[i] = malloc(sizeof(char) * (data->width + 1));
		if (!map_copy[i])
			ft_map_copy_error(data, "Failed to allocate memory : map_copy[i]");
		j = 0;
		while (j < data->width - 1)
		{
			map_copy[i][j] = data->map[i][j];
			j++;
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	init_player_pos(t_data *data)
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
				data->pos.x = i;
				data->pos.y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		ft_map_error(data, "Failed to get mlx_ptr");
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			(data->width - 1) * 64, data->height * 64, "seaulongue");
	if (!data->win_ptr)
		ft_mlx_error(data, "Failed to get win_ptr");
}

void	init_mlx(t_data *data)
{
	init_window(data);
	draw_map(data);
}

void	init_data(t_data *data, char *map_path)
{
	data->map = map_core(data, map_path);
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->height = get_height(data);
	data->width = get_width(data, data->height);
	data->content.count_c = get_colls(data);
	data->content.count_e = get_exits(data);
	data->content.count_p = get_start(data);
	data->map_copy = init_map_copy(data);
	is_map_valid(data);
	init_mlx(data);
}
