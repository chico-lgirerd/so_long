/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:44:37 by lgirerd           #+#    #+#             */
/*   Updated: 2025/02/05 14:02:52 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	void	*mlx_ptr;
	void	*window_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	window_ptr = mlx_new_window(mlx_ptr, 3840, 2160, "test by Louie");
	if (!window_ptr)
		return (free(mlx_ptr), 1);
	sleep(5);
	mlx_destroy_window(mlx_ptr, window_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	return (0);	
}
