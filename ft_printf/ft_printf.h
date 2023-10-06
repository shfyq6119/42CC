/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 02:42:14 by mm-isa            #+#    #+#             */
/*   Updated: 2023/10/06 15:32:44 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEXUP "0123456789ABCDEF"
# define HEXLOW "0123456789abcdef"
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_n(char c);
int	ft_putstr_n(char *s);
int	ft_putnbr_n(long i);
int	ft_putaddr_n(unsigned long p);
int	ft_puthex_n(unsigned long h, char *hexcase);

#endif
