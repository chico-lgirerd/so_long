/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:28:07 by lgirerd           #+#    #+#             */
/*   Updated: 2024/12/12 16:26:51 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	if (!src)
		return (0);
	s_len = 0;
	d_len = ft_strlen(dst);
	i = ft_strlen(dst);
	if (size <= d_len)
		return (size + ft_strlen(src));
	while (src[s_len] && i < size - 1)
	{
		dst[i] = src[s_len];
		i++;
		s_len++;
	}
	dst[i] = '\0';
	return (d_len + ft_strlen(src));
}
