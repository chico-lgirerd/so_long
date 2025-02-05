/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:55:37 by lgirerd           #+#    #+#             */
/*   Updated: 2024/12/17 13:58:52 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*d;

	i = 0;
	d = malloc((ft_strlen((char *)s) * sizeof(char)) + 1);
	if (d == NULL)
		return (NULL);
	while (i < ft_strlen((char *)s))
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

int	num_len(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len = 1;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*reverse(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (j > i)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	return (str);
}

char	*num_handler(int n)
{
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else
		return (ft_strdup("0"));
}

char	*ft_itoa(int nb)
{
	char	*res;
	int		i;
	int		sign;
	int		len;

	if (nb == -2147483648 || nb == 0)
		return (num_handler(nb));
	len = num_len(nb);
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	sign = (nb < 0);
	if (sign)
		nb = -nb;
	while (nb)
	{
		res[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	if (sign)
		res[i++] = '-';
	res[i] = '\0';
	return (reverse(res));
}
