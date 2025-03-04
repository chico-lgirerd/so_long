/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:06:27 by lgirerd           #+#    #+#             */
/*   Updated: 2025/03/04 17:19:23 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	ft_error(char *msg)
{
	ft_printf("Error\n%s\n", msg);
	exit(1);
}

void	ft_map_error(t_data *data, char *msg)
{
	free_map(data);
	free(data);
	ft_error(msg);
}

void	ft_gnl_error(t_data *data, char *line, char *msg)
{
	free(line);
	ft_map_error(data, msg);
}

void	ft_map_copy_error(t_data *data, char *msg)
{
	free_map_copy(data);
	ft_map_error(data, msg);
}

void	ft_mlx_error(t_data *data, char *msg)
{
	free(data->mlx_ptr);
	ft_map_error(data, msg);
}
