/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:15:36 by lgirerd           #+#    #+#             */
/*   Updated: 2025/02/26 13:55:44 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_image
{
	int	width;
	int	height;
}	t_image;

typedef struct s_content
{
	char	player;
	char	collectibles;
	char	exit;
	int		count_p;
	int		count_c;
	int		count_e;
	int		found_c;
	int		found_e;
}	t_content;

typedef struct s_data
{
	char		**map;
	char		**map_copy;
	void		*mlx_ptr;
	void		*win_ptr;
	int			height;
	int			width;
	int			count;
	t_player	pos;
	t_content	content;
	t_image		img;
}	t_data;

void	init_data(t_data *data, char *map_path);

#endif
