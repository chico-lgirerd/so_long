/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:17:14 by lgirerd           #+#    #+#             */
/*   Updated: 2024/12/17 13:59:30 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include <unistd.h>

int	ft_handler(va_list args, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_printchar(va_arg(args, int));
	if (format == 's')
		print_len += ft_printstr(va_arg(args, char *));
	if (format == 'p')
		print_len += ft_printptr(va_arg(args, unsigned long long));
	if (format == 'd' || format == 'i')
		print_len += ft_printnumber(va_arg(args, int));
	if (format == 'u')
		print_len += ft_printunsigned(va_arg(args, unsigned int));
	if (format == 'x')
		print_len += ft_printhex(va_arg(args, unsigned int), 'x');
	if (format == 'X')
		print_len += ft_printhex(va_arg(args, unsigned int), 'X');
	if (format == '%')
		print_len += write(1, "%", 1);
	return (print_len);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		print_len;
	va_list	args;

	if (s == NULL)
		return (-1);
	i = 0;
	print_len = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			print_len += ft_handler(args, s[i + 1]);
			i++;
		}
		else
			print_len += ft_printchar(s[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}
