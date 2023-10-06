# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/06 13:05:10 by mm-isa            #+#    #+#              #
#    Updated: 2023/10/06 15:05:45 by mm-isa           ###   ########.fr        #
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

all		=	$(NAME)

$(NAME)	:	$(OBJS)
			@echo "$(NAME) - i maketh the library..."
			$(GCC) $(GFLAGS) -c $(SRC) -I./
			ar rc $(NAME) $(OBJS)

clean	:	
			@echo "$(NAME) - i destroyeth the object files.."
			rm -f $(OBJS)

fclean	:	clean
			@echo "$(NAME) - i annihilate everything!!! jk"

re		:	fclean all
			@echo "$(NAME) - i recreateh as i will! jk uWu"

.PHONY	:	all clean fclean re
