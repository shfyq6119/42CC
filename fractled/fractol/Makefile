# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/16 01:33:24 by mm-isa            #+#    #+#              #
#    Updated: 2024/06/16 06:05:37 by mm-isa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol
CC		=	cc
CFLAGS	=	-g -Wall -Wextra -Werror -Wno-deprecated-non-prototype -Iminilibx_macos

SRCDIR	=	./srcs
SRC 	=	fractol.c \
			fract_all.c \
			fract_utils.c \
			keys.c
			
SRCPATH	=	$(addprefix $(SRCDIR)/, $(SRC))

OBJDIR = objects
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCPATH))

FRACTOL	=	./includes
LIBMLX	=	./includes/minilibx_macos
LIBFT	=	./includes/libft
MLX		=	-L$(LIBMLX)/ -lmlx -framework OpenGL -framework AppKit
LFT		=	-L$(LIBFT)/ -lft

INC		=	-I$(FRACTOL) -I$(LIBFT) -I$(LIBMLX)

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) $(OBJS) $(CFLAGS) $(LFT) $(MLX) -o $(NAME)

clean:
	make -C $(LIBFT)
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

