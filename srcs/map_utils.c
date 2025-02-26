/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:43:58 by lgirerd           #+#    #+#             */
/*   Updated: 2025/02/26 21:21:32 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int	get_height(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
		i++;
	return (i);
}

int	get_width(t_data *data, int height)
{
	size_t	len_1;
	int		i;

	len_1 = ft_strlen(data->map[0]);
	i = 1;
	while (data->map[i] != NULL)
	{
		if (ft_strlen(data->map[i]) != len_1)
			ft_map_error(data, "Variating widths");
		i++;
	}
	if ((size_t)height >= len_1 - 1)
		ft_map_error(data, "Map is not rectangular");
	return (len_1);
}

int	get_exits(t_data *data)
{
	int	i;
	int	j;
	int	count_e;

	i = 0;
	count_e = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] != '\n')
		{
			if (data->map[i][j] == 'E')
				count_e++;
			j++;
		}
		i++;
	}
	if (count_e == 0 || count_e > 1)
		ft_map_error(data, "Incorrect exit(s)");
	return (count_e);
}

int	get_start(t_data *data)
{
	int	i;
	int	j;
	int	count_p;

	i = 0;
	count_p = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] != '\n')
		{
			if (data->map[i][j] == 'P')
				count_p++;
			j++;
		}
		i++;
	}
	if (count_p == 0 || count_p > 1)
		ft_map_error(data, "Incorrect starting point(s)");
	return (count_p);
}

int	get_colls(t_data *data)
{
	int	i;
	int	j;
	int	count_c;

	i = 0;
	count_c = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] != '\n')
		{
			if (data->map[i][j] == 'C')
				count_c++;
			j++;
		}
		i++;
	}
	if (count_c == 0)
		ft_map_error(data, "Too few collectibles");
	return (count_c);
}
