# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 23:50:19 by mm-isa            #+#    #+#              #
#    Updated: 2024/06/17 00:51:53 by mm-isa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	ft_atod.c \
			ft_atoi.c \
		  	ft_bzero.c \
		  	ft_calloc.c \
			ft_free.c \
		  	ft_isalnum.c \
		  	ft_isalpha.c \
		  	ft_isascii.c \
		  	ft_isdigit.c \
			ft_isdouble.c \
		  	ft_isprint.c \
		  	ft_itoa.c \
		  	ft_memchr.c \
		  	ft_memcmp.c \
		  	ft_memcpy.c \
		  	ft_memmove.c \
		  	ft_memset.c \
		  	ft_putchar_fd.c \
		  	ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_printf.c \
			ft_putchar_n.c \
			ft_putstr_n.c \
			ft_putnbr_n.c \
			ft_putaddr_n.c \
			ft_puthex_n.c \
			ft_lstadd_back_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstmap_bonus.c \
			ft_lstnew_bonus.c \
			ft_lstsize_bonus.c 

OBJDIR 		= objects

OBJS 		= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

FLAGS		= -Wall -Wextra -Werror

all				:	$(NAME)

$(OBJDIR)		:
				mkdir -p $(OBJDIR)

$(OBJDIR)/%.o	: %.c | $(OBJDIR)
			  	cc $(FLAGS) -I./ -c $< -o $@

$(NAME)			: $(OBJDIR) $(OBJS)
				ar rc $(NAME) $(OBJS)

clean			:
					rm -rf $(OBJDIR)

fclean			:	clean
					rm -f $(NAME)

re				:	fclean all

.PHONY			:	all clean fclean re
