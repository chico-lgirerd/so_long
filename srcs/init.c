/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:16:54 by lgirerd           #+#    #+#             */
/*   Updated: 2025/03/05 15:55:25 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

char	**init_map_copy(t_data *data)
{
	int		x;
	int		y;
	char	**map_copy;

	map_copy = malloc(sizeof(char *) * (data->height + 1));
	if (!map_copy)
		ft_map_error(data, "Failed to allocate memory : map_copy");
	y = 0;
	while (y < data->height)
	{
		map_copy[y] = malloc(sizeof(char) * (data->width + 1));
		if (!map_copy[y])
			ft_map_copy_error(data, "Failed to allocate memory : map_copy[y]");
		x = 0;
		while (x < data->width - 1)
		{
			map_copy[y][x] = data->map[y][x];
			x++;
		}
		y++;
	}
	map_copy[y] = NULL;
	return (map_copy);
}

void	init_player_pos(t_data *data)
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
				data->player.width = x;
				data->player.height = y;
				return ;
			}
			x++;
		}
		y++;
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
		clean_error(data, "Failed to get win_ptr");
}

void	init_mlx(t_data *data)
{
	init_window(data);
	load_images(data);
}

void	init_data(t_data *data, char *map_path)
{
	data->map = map_core(data, map_path);
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->player.colls = 0;
	init_img_pointers(data);
	data->height = get_height(data);
	data->width = get_width(data, data->height);
	data->content.count_c = get_colls(data);
	data->content.count_e = get_exits(data);
	data->content.count_p = get_start(data);
	data->map_copy = init_map_copy(data);
	is_map_valid(data);
	init_mlx(data);
}
