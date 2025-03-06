/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:16:52 by lgirerd           #+#    #+#             */
/*   Updated: 2025/03/06 16:56:17 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define DESTROYNOTIFY 17
# define TILE_SIZE 64
# define CHAR_WALL '1'
# define CHAR_EMPTY '0'
# define CHAR_COLL 'C'
# define CHAR_EXIT 'E'
# define CHAR_PLAYER 'P'
# define FRAME_UP 1
# define FRAME_RIGHT 2
# define FRAME_DOWN 3
# define FRAME_LEFT 4

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h> 

typedef struct s_player
{
	int		width;
	int		height;
	void	*left;
	void	*right;
	void	*up;
	void	*down;
	int		direction;
	int		colls;
}	t_player;

typedef struct s_image
{
	void	*wall;
	void	*empty;
	void	*colls;
	void	*exit;
	void	*start;
	void	*playerstart;
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
	int			moves;
	t_player	player;
	t_content	content;
	t_image		sprites;
}	t_data;

void	ft_error(t_data *data, char *msg);
void	free_map(t_data *data);
void	free_map_copy(t_data *data);
void	init_data(t_data *data, char *map_path);
void	init_player_pos(t_data *data);
char	**map_core(t_data *data, char *map_path);
int		get_height(t_data *data);
int		get_width(t_data *data, int height);
void	check_walls(t_data *data);
void	free_map(t_data *data);
int		get_exits(t_data *data);
int		get_start(t_data *data);
int		get_colls(t_data *data);
void	is_map_valid(t_data *data);
void	draw_map(t_data *data);
void	load_images(t_data *data);
void	free_images(t_data *data);
int		clean_exit(t_data *data);
void	draw_player(t_data *data, int dir);
int		key_hook(int keycode, t_data *data);
void	init_player(t_data *data);

#endif 
