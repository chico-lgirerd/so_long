/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:07:54 by lgirerd           #+#    #+#             */
/*   Updated: 2025/02/26 21:09:09 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structs.h"

void	ft_error(char *msg);
void	ft_map_error(t_data *data, char *msg);
void	ft_gnl_error(t_data *data, char *line, char *msg);
void	ft_map_copy_error(t_data *data, char *msg);
void	free_map(t_data *data);
void	free_map_copy(t_data *data);
void	ft_mlx_error(t_data *data, char *msg);

#endif
