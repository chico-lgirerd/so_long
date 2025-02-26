/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:16:54 by lgirerd           #+#    #+#             */
/*   Updated: 2025/02/26 13:12:14 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "utils.h"
#include "map.h"
#include <stddef.h>

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
}

char	**init_map_copy(t_data *data)
{
	int		i;
	int		j;
	char	**map_copy;

	map_copy = malloc(sizeof(char *) * data->height);
	if (!map_copy)
		ft_map_error(data, "Failed to allocate memory : map_copy");
	i = 0;
	while (i < data->height)
	{
		map_copy[i] = malloc(sizeof(char) * data->width);
		if (!map_copy[i])
			ft_map_copy_error(data, "Failed to allocate memory : map_copy[i]");
		j = 0;
		while (j < data->width)
		{
			map_copy[i][j] = data->map[i][j];
			j++;
		}
		i++;
	}
	return (map_copy);
}
