/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:43:58 by lgirerd           #+#    #+#             */
/*   Updated: 2025/02/19 15:51:18 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include <stdlib.h>

int	get_height(t_data *data)
{
	int	i;
	
	i = 0;
	while (data->map[i] != NULL)
		i++;
	return (i);
}

int	get_width(t_data *data)
{
	size_t	len_1;
	int		i;

	len_1 = ft_strlen(data->map[0]);
	i = 1;
	while (data->map[i] != NULL)
	{
		if (ft_strlen(data->map[i]) != len_1)
			ft_map_error(data, "Incorrect map. Please check all lines are the same width");
		i++;
	}
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
