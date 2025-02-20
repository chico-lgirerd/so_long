/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:43:58 by lgirerd           #+#    #+#             */
/*   Updated: 2025/02/20 13:01:34 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include <stdlib.h>

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
		ft_map_error(data, "Incorrect map : must have one exit");
	return (count_e);
}
