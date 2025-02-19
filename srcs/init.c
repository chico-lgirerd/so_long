/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:16:54 by lgirerd           #+#    #+#             */
/*   Updated: 2025/02/19 14:45:16 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "map.h"
#include <stddef.h>

void	init_data(t_data *data, char *map_path)
{
	data->map = map_core(map_path);
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->height = get_height(data->map);
	data->width = get_width(data->map);
}
