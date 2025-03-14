/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_core.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:17:43 by lgirerd           #+#    #+#             */
/*   Updated: 2025/03/13 15:09:39 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int	name_checker(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 4)
		return (1);
	if (ft_strncmp(&str[len - 4], ".ber", 4) != 0)
		return (1);
	return (0);
}

int	line_count(int fd)
{
	char	buf[BUF_SIZE];
	int		counter;
	int		b_read;
	int		i;

	counter = 0;
	b_read = 1;
	while (b_read)
	{
		i = 0;
		b_read = read(fd, buf, BUF_SIZE);
		if (b_read < 0)
			return (0);
		while (i < b_read)
		{
			if (buf[i] == '\n')
				counter++;
			i++;
		}
	}
	return (counter);
}

char	**get_map(t_data *data, int fd, int lines)
{
	char	**map;
	int		i;
	char	*line;

	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		ft_error(data, "Failed to allocate memory : map");
	i = 0;
	line = get_next_line(fd);
	if (!line)
	{
		free(map);
		ft_error(data, "Failed get_next_line");
	}
	while (line != NULL)
	{
		map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	free(line);
	map[i] = NULL;
	return (map);
}

char	**map_core(t_data *data, char *map_path)
{
	int		fd;
	int		i;
	char	**map;

	if (name_checker(map_path))
		ft_error(data, "Incorrect map format. Usage : ./so_long map.ber");
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		ft_error(data, "Error while opening file");
	i = line_count(fd);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		ft_error(data, "Error while opening file");
	map = get_map(data, fd, i);
	close(fd);
	return (map);
}

void	check_walls(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->width - 1)
	{
		if (data->map[0][x] != CHAR_WALL)
			ft_error(data, "Incorrect walls : first line");
		x++;
	}
	y = 0;
	while (y < data->height - 1)
	{
		if (data->map[y][0] != CHAR_WALL
			|| data->map[y][data->width - 2] != CHAR_WALL)
			ft_error(data, "Incorrect walls : columns");
		y++;
	}
	x = 0;
	while (x < data->width - 1)
	{
		if (data->map[data->height - 1][x] != CHAR_WALL)
			ft_error(data, "Incorrect walls : last line");
		x++;
	}
}
