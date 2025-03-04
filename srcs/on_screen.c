/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:33:31 by lgirerd           #+#    #+#             */
/*   Updated: 2025/03/04 17:47:34 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "libft.h"

void	draw_char(t_data *data, char c, int color, int offset)
{
	int spacing;
	int	x;
	int	y;

	y = 0;
	spacing = 50 + offset;
	while (y < 10)
	{
		x = 0;
		while (x < 6)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, spacing + x * 3, 50 + y * 3, color);
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, spacing + x * 3 + 1, 50 + y * 3, color);
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, spacing + x * 3, 50 + y * 3 + 1, color);
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, spacing + x * 3 + 1, 50 + y * 3 + 1, color);
			x++;
		}
		y++;
	}
}

void	draw_string(t_data *data, char *str, int color)
{
	int	offset;

	offset = 0;
	while (*str)
	{
		draw_char(data, *str, color, offset);
		str++;
		offset += 20;
	}
}

void	draw_moves(t_data *data, int moves)
{
	char	*string;
	
	string = ft_itoa(moves);
	if (!string)
		clean_error(data, "Failed to allocate : itoa");
	draw_string(data, string, 0x00FFFFFF);
	free(string);
}
