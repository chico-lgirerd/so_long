/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:48:50 by lgirerd           #+#    #+#             */
/*   Updated: 2024/12/12 15:20:59 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	char			*cs;
	unsigned char	uc;

	cs = (char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)cs[i] == uc)
			return (cs + i);
		i++;
	}
	return ((void *)(0));
}
