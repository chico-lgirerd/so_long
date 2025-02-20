/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:06:27 by lgirerd           #+#    #+#             */
/*   Updated: 2025/02/20 14:31:17 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "structs.h"
#include <stdlib.h>

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

void	ft_error(char *msg)
{
	ft_printf("Error\n%s\n", msg);
	exit(1);
}

void	ft_map_error(t_data *data, char *msg)
{
	free_map(data);
	ft_error(msg);
}

void	ft_gnl_error(t_data *data, char *line, char *msg)
{
	free(line);
	ft_map_error(data, msg);
}
