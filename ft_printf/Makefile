# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/06 13:05:10 by mm-isa            #+#    #+#              #
#    Updated: 2023/10/08 20:18:17 by mm-isa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	=	libftprintf.a

GCC		= 	gcc

GFLAGS 	=	-g -Wall -Wextra -Werror

SRC 	=	ft_printf.c \
			ft_putchar_n.c \
			ft_putstr_n.c \
			ft_putnbr_n.c \
			ft_putaddr_n.c \
			ft_puthex_n.c \

OBJS	=	$(SRC:%.c=%.o)

$(NAME)	:	$(OBJS)
			@echo "$(NAME)- i maketh the library..."
			gcc $(GFLAGS) -c $(SRC) -I./
			ar rc $(NAME) $(OBJS)

all		:	$(NAME)

clean	:	
			@echo "$(NAME) - i destroyeth the objecteth files.."
			rm -f $(OBJS)

fclean	:	clean
			@echo "$(NAME) - i annihilateth everythingeth!!! jk"
			rm -f $(NAME)

re		:	fclean all
			@echo "$(NAME) - i recreateth as i willeth! jk uWu"

.PHONY	:	all clean fclean re
