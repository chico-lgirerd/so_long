/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:26:29 by lgirerd           #+#    #+#             */
/*   Updated: 2025/02/27 15:48:56 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	draw_wall(t_data *data, int x, int y)
{
	int	width;
	int	height;

	data->img.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "img/wall.xpm", &width, &height);
	if (!data->img.img_ptr)
		ft_mlx_error(data, "Failed to get image");
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, x, y);
}

void	draw_space(t_data *data, int x, int y)
{
	int	width;
	int	height;

	data->img.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "img/empty.xpm", &width, &height);
	if (!data->img.img_ptr)
		ft_mlx_error(data, "Failed to get image");
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, x, y);
}

void	draw_colls(t_data *data, int x, int y)
{
	int	width;
	int	height;

	data->img.img_ptr = mlx_xpm_to_image(data->mlx_ptr, "img/colls.xpm", &width, &height);
	if (!data->img.img_ptr)
		ft_mlx_error(data, "Failed to get image");
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, x, y);	
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] == '1')
				draw_wall(data, j * 64, i * 64);
			else if (data->map[i][j] == '0')
				draw_space(data, j * 64, i * 64);
			else if (data->map[i][j] == 'C')
				draw_colls(data, j * 64, i * 64);
			j++;
		}
		i++;
	}
	sleep(10);
}
