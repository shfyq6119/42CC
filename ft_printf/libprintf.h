/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 02:42:14 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/27 20:31:53 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBPRINTF_H
# define LIBPRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c);
char	*ft_itoa(int c);
void	ft_putnbr_base(int c);
void	ft_hexcase(int c);
void	ft_p


#endif
