/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:06:27 by lgirerd           #+#    #+#             */
/*   Updated: 2025/02/19 15:51:27 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "structs.h"
#include "map.h"
#include <stdlib.h>

void	ft_error(char *msg)
{
	ft_printf("Error\n%s\n", msg);
	exit(1);
}

void	ft_map_error(t_data *data, char *msg)
{
	free_map(data);
	ft_error(msg);
}
