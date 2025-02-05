/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_core.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:17:43 by lgirerd           #+#    #+#             */
/*   Updated: 2025/02/05 15:01:27 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	char_checker(int fd)
{
	
}

int	map_checking(char *path)
{
	int	fd;
	
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	if (char_checker(fd))
	{
		
	}
}
