/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:49:46 by lgirerd           #+#    #+#             */
/*   Updated: 2025/02/05 15:36:42 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include <stdlib.h>

char	*ft_itoa_unsigned(unsigned int n)
{
	char			*s;
	unsigned int	tmp;
	int				len;

	tmp = n;
	len = 1;
	while (tmp / 10 > 0)
	{
		tmp /= 10;
		len++;
	}
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	s[len] = '\0';
	while (len--)
	{
		s[len] = n % 10 + '0';
		n /= 10;
	}
	return (s);
}

int	ft_printunsigned(unsigned int n)
{
	int		len;
	char	*num;

	num = ft_itoa_unsigned(n);
	len = ft_printstr(num);
	free(num);
	return (len);
}
