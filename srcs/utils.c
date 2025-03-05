/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:06:27 by lgirerd           #+#    #+#             */
/*   Updated: 2025/03/05 16:26:03 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	ft_error(t_data *data, char *msg)
{
	ft_printf("Error\n%s\n", msg);
	if (data)
	{
		free(data);
		data = NULL;
	}
	exit(1);
}

void	ft_map_error(t_data *data, char *msg)
{
	if (data->map)
		free_map(data);
	ft_error(data, msg);
}

void	ft_gnl_error(t_data *data, char **map, char *line, char *msg)
{
	int	y;

	if (line)
		free(line);
	if (map)
	{
		y = 0;
		while (map[y])
		{
			free(map[y]);
			y++;
		}
		free(map);
	}
	ft_error(data, msg);
}

void	ft_map_copy_error(t_data *data, char *msg)
{
	free(data->map_copy);
	ft_map_error(data, msg);
}

void	ft_mlx_error(t_data *data, char *msg)
{
	free(data->mlx_ptr);
	ft_map_error(data, msg);
}
