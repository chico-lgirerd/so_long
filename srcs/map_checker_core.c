/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_core.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:17:43 by lgirerd           #+#    #+#             */
/*   Updated: 2025/02/10 17:28:30 by lgirerd          ###   ########lyon.fr   */
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
	while ((line = get_next_line(fd)) != NULL)
	{
		map[i] = ft_strdup(line);
		free(line);
		if (!map[i])
			return (1);
		i++;
	}
	int j = 0;
	while (map[j])
	{
		ft_printf(map[0]);
		j++;
	}
	close(fd);
	return (0);
}

int	main(void)
{
	if (map_core("map.ber"))
		return (1);
	return (0);
}

