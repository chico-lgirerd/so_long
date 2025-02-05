/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_core.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:17:43 by lgirerd           #+#    #+#             */
/*   Updated: 2025/02/05 16:47:55 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
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

int	map_checking_core(char *path)
{
	int	fd;
	
	if (name_checker(path))
		return (1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
}
