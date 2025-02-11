/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_core.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:17:43 by lgirerd           #+#    #+#             */
/*   Updated: 2025/02/11 15:42:28 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "../include/structs.h"
#include <fcntl.h>
#include <stdlib.h> 
#include <unistd.h>

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

int	map_core(char *map_path)
{
	int		fd;
	int		i;
	char	**map = NULL;
	char	*line;

	if (name_checker(map_path))
		return (1);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (1);
	i = 0;
	map = malloc(sizeof(char *) * 5);
	map[4] = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{ 
		ft_printf("GNL : %s", line);
		map[i] = malloc(ft_strlen(line));
		ft_strlcpy(map[i], line, ft_strlen(line));
		free(line);
		//map[i] = line2;
		// if (!map[i])
		// 	return (1);
		i++;
	}
	int j = 0;
	ft_printf("== MAP ==\n");
	while (j < 5)
	{
		ft_printf("%s\n", map[j]);
		j++;
	}
	j = 0;
	while (j < 5)
	{
		free(map[j]);
		j++;
	}
	free(map);
	close(fd);
	return (0);
}

int	main(void)
{
	if (map_core("map.ber"))
		return (1);
	return (0);
}

