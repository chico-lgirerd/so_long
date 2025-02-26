/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:42:56 by lgirerd           #+#    #+#             */
/*   Updated: 2025/02/26 14:16:49 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "structs.h"

char	**map_core(t_data *data, char *map_path);
int		get_height(t_data *data);
int		get_width(t_data *data, int height);
void	check_walls(t_data *data);
void	free_map(t_data *data);
int		get_exits(t_data *data);
int		get_start(t_data *data);
int		get_colls(t_data *data);
void	is_map_valid(t_data *data);

#endif 
