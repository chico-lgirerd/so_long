/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:39:47 by lgirerd           #+#    #+#             */
/*   Updated: 2024/12/12 16:26:51 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include <stdlib.h>

int	ft_strstrchr(const char *set, const char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		start;
	int		end;
	int		resi;

	start = 0;
	while (s1[start] && ft_strstrchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && ft_strstrchr(set, s1[end]))
		end--;
	res = malloc((end - start + 2) * sizeof(char));
	if (res == NULL)
		return (NULL);
	resi = 0;
	while (start <= end)
		res[resi++] = s1[start++];
	res[resi] = '\0';
	return (res);
}

/*
int	main()
{
	char	*test = ft_strtrim("filsiiicoucoulisf", "fils");
	printf("%s", test);
	return (0);
}*/
