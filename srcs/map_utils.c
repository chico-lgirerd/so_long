/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:43:58 by lgirerd           #+#    #+#             */
/*   Updated: 2025/02/19 14:57:04 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include <stdlib.h>

int	get_height(char **map)
{
	int	i;
	
	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

int	get_width(char **map)
{
	size_t	len_1;
	int		i;

	len_1 = ft_strlen(map[0]);
	i = 1;
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) != len_1)
			ft_error("Incorrect map. Please check all lines are the same width");
		i++;
	}
	return (len_1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
