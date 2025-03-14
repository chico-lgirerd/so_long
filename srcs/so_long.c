/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:12:34 by lgirerd           #+#    #+#             */
/*   Updated: 2025/03/06 17:14:42 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		return (0);
	data = malloc(sizeof(t_data));
	if (!data)
		ft_error(data, "Failed to allocate : data");
	init_data(data, av[1]);
	draw_map(data);
	init_player(data);
	mlx_key_hook(data->win_ptr, key_hook, data);
	mlx_hook(data->win_ptr, DESTROYNOTIFY, 1L << 17, clean_exit, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
