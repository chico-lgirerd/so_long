/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:42:56 by lgirerd           #+#    #+#             */
/*   Updated: 2025/02/19 16:23:00 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include "structs.h"

char	**map_core(char *map_path);
int		get_height(t_data *data);
int		get_width(t_data *data);
void	check_walls(t_data *data);
void	free_map(t_data *data);

#endif 
