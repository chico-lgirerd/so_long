/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:06:27 by lgirerd           #+#    #+#             */
/*   Updated: 2025/02/26 19:16:13 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "structs.h"
#include "utils.h"
#include <stdlib.h>

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

void	ft_map_copy_error(t_data *data, char *msg)
{
	int	i;

	i = 0;
	while (data->map_copy[i] != NULL)
	{
		free(data->map_copy[i]);
		i++;
	}
	free(data->map_copy);
	ft_map_error(data, msg);
}

void	ft_mlx_error(t_data *data, char *msg)
{
	free(data->mlx_ptr);
	ft_map_error(data, msg);
}
