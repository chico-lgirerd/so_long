/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:16:52 by lgirerd           #+#    #+#             */
/*   Updated: 2025/03/13 15:49:06 by lgirerd          ###   ########lyon.fr   */
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
# define BUF_SIZE 65536

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

/**
 * @brief Frees memory previously and exits with code 1
 * 
 * @param data Structure containing the whole game
 * @param msg Message displayed on exit
 * 
 * @note Protected against double frees
 * @see free, exit, t_data
 */
void	ft_error(t_data *data, char *msg);

/**
 * @brief Frees the whole map char**
 * 
 * @param data Structure containing the whole game
 *  
 * @note Sets data->map to NULL
 * @see free, t_data
 */
void	free_map(t_data *data);

/**
 * @brief Frees the whole map copy char**
 * 
 * @param data Structure containing the whole game
 * 
 * @note Sets data->map_copy to NULL
 * @see free, t_data
 */
void	free_map_copy(t_data *data);

/**
 * @brief Initializes the data structure
 * 
 * @param data Structure containing the whole game
 * @param map_path The path of the map file (.ber)
 * 
 * @note Continues by initalizing mlx_ptr
 * @see ft_memset
 */
void	init_data(t_data *data, char *map_path);

/**
 * @brief Initializes the player's starting position
 * 
 * @param data Structure containing the whole game
 */
void	init_player_pos(t_data *data);

/**
 * @brief Fetches the map
 * 
 * @param data Structure containing the whole game
 * @param map_path The path of the map file (.ber)
 * 
 * @return Map in a char** format to be put in data->map
 * @note Uses get_next_line to fetch map
 * @see get_next_line
 */
char	**map_core(t_data *data, char *map_path);

/**
 * @brief Returns the map height
 * 
 * @param data Structure containing the whole game
 * 
 * @return Height of the map
 */
int		get_height(t_data *data);

/**
 * @brief Returns the map width
 * 
 * @param data Structure containing the whole game
 * @param height Map height
 * 
 * @note Also checks for a square map
 * @return Width of the map
 */
int		get_width(t_data *data, int height);

/**
 * @brief Checks for correct map enclosure
 * 
 * @param data Structure containing the whole game
 * 
 * @note Will go into ft_error if a wall is wrong
 */
void	check_walls(t_data *data);

/**
 * @brief Frees the map
 * 
 * @param data Structure containing the whole game * 
 */
void	free_map(t_data *data);

/**
 * @brief Returns the count of exits in the map
 * 
 * @param data Structure containing the whole game
 * 
 * @return Number of exits
 */
int		get_exits(t_data *data);

/**
 * @brief Returns the count of starts in the map
 * 
 * @param data Structure containing the whole game
 * 
 * @return Number of starting positions
 */
int		get_start(t_data *data);

/**
 * @brief Returns the count of collectibles in the map
 * 
 * @param data Structure containing the whole game
 * 
 * @return Number of collectibles
 */
int		get_colls(t_data *data);

/**
 * @brief Checks if the map is playable
 * 
 * @param data Structure containing the whole game
 * 
 * @note Uses flood_fill
 */
void	is_map_valid(t_data *data);

/**
 * @brief Draws the map at every movement
 * 
 * @param data Structure containing the whole game
 */
void	draw_map(t_data *data);

/**
 * @brief Loads the images through mlx
 * 
 * @param data Structure containing the whole game
 */
void	load_images(t_data *data);

/**
 * @brief Frees the images
 * 
 * @param data Structure containing the whole game
 */
void	free_images(t_data *data);

/**
 * @brief Exits the program with 0 after freeing memory
 * 
 * @param data Structure containing the whole game
 */
int		clean_exit(t_data *data);

/**
 * @brief Draws the player's frame while moving
 * 
 * @param data Structure containing the whole game
 * @param dir Direction of the player
 */
void	draw_player(t_data *data, int dir);

/**
 * @brief Registers every key pressed
 * 
 * @param keycode Integer representing the key pressed
 * @param data Structure containing the whole game
 */
int		key_hook(int keycode, t_data *data);

/**
 * @brief Draws the player standing on the start position
 * 
 * @param data Structure containing the whole game
 */
void	init_player(t_data *data);

#endif 
