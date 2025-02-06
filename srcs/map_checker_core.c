/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_core.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:17:43 by lgirerd           #+#    #+#             */
/*   Updated: 2025/02/06 12:58:12 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "../include/structs.h"
#include <fcntl.h>
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
	char	**map;
	
	if (name_checker(map_path))
		return (1);
	
}
