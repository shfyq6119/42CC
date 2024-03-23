/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 02:40:34 by mm-isa            #+#    #+#             */
/*   Updated: 2023/10/06 17:14:09 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static size_t	parse_print(char idx, va_list args)
{
	size_t	count;

	count = 0;
	if (idx == 'c')
		count = ft_putchar_n(va_arg(args, int));
	else if (idx == 's')
		count = ft_putstr_n(va_arg(args, char *));
	else if (idx == 'd' || idx == 'i')
		count = ft_putnbr_n(va_arg(args, int));
	else if (idx == 'u')
		count = ft_putnbr_n(va_arg(args, unsigned int));
	else if (idx == 'p')
		count = ft_putaddr_n(va_arg(args, unsigned long));
	else if (idx == 'x')
		count = ft_puthex_n(va_arg(args, unsigned int), HEXLOW);
	else if (idx == 'X')
		count = ft_puthex_n(va_arg(args, unsigned int), HEXUP);
	else if (idx == '%')
		count = ft_putchar_n('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	parse;
	int		idx;
	int		tally;

	idx = 0;
	tally = 0;
	va_start(parse, format);
	while (format[idx])
	{
		if (format[idx] == '%')
			tally += parse_print(format[++idx], parse);
		else
			tally += ft_putchar_n(format[idx]);
		idx++;
	}
	va_end(parse);
	return (tally);
}
