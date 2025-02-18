/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_core.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:17:43 by lgirerd           #+#    #+#             */
/*   Updated: 2025/02/18 14:31:46 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "structs.h"
#include <fcntl.h>
#include <stdlib.h> 
#include <unistd.h>

#define BUF_SIZE 65536

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

char	**get_map(int fd, int lines)
{
	char	**map;
	int		i;
	char	*line;

	map = malloc(sizeof(char *) * (lines + 1));
	map[lines + 1] = NULL;
	i = 0;
	line = get_next_line(fd);
	if (!line)
		exit(1);
	while (line != NULL)
	{
		map[i] = malloc(ft_strlen(line) + 1);
		if (!map[i])
		{
			free(line);
			exit(1);
		}
		ft_strlcpy(map[i], line, ft_strlen(line) + 1);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	return (map);
}

int	map_core(t_data *game, char *map_path)
{
	int		fd;
	int		i;
	char	**map;

	if (name_checker(map_path))
		return (1);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (1);
	i = line_count(fd);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (1);
	map = get_map(fd, i);
	game->map = map;
	free(map);
	close(fd);
	return (0);
}

int	main(void)
{
	game = NULL;
	if (map_core(game, "map.ber"))
		return (1);
	return (0);
}
