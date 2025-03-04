/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:43:58 by lgirerd           #+#    #+#             */
/*   Updated: 2025/03/04 16:14:52 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int	get_height(t_data *data)
{
	int	y;

	y = 0;
	while (data->map[y])
		y++;
	return (y);
}

int	get_width(t_data *data, int height)
{
	size_t	len_1;
	int		y;

	len_1 = ft_strlen(data->map[0]);
	y = 1;
	while (data->map[y] != NULL)
	{
		if (ft_strlen(data->map[y]) != len_1)
			ft_map_error(data, "Variating widths");
		y++;
	}
	if ((size_t)height >= len_1 - 1)
		ft_map_error(data, "Map is not rectangular");
	return (len_1);
}

int	get_exits(t_data *data)
{
	int	x;
	int	y;
	int	count_e;

	y = 0;
	count_e = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x] != '\n')
		{
			if (data->map[y][x] == 'E')
				count_e++;
			x++;
		}
		y++;
	}
	if (count_e == 0 || count_e > 1)
		ft_map_error(data, "Incorrect exit(s)");
	return (count_e);
}

int	get_start(t_data *data)
{
	int	x;
	int	y;
	int	count_p;

	y = 0;
	count_p = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x] != '\n')
		{
			if (data->map[y][x] == 'P')
				count_p++;
			x++;
		}
		y++;
	}
	if (count_p == 0 || count_p > 1)
		ft_map_error(data, "Incorrect starting point(s)");
	return (count_p);
}

int	get_colls(t_data *data)
{
	int	x;
	int	y;
	int	count_c;

	y = 0;
	count_c = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x] != '\n')
		{
			if (data->map[y][x] == 'C')
				count_c++;
			x++;
		}
		y++;
	}
	if (count_c == 0)
		ft_map_error(data, "Too few collectibles");
	return (count_c);
}
