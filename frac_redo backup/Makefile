# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/16 01:33:24 by mm-isa            #+#    #+#              #
#    Updated: 2024/06/28 16:36:36 by mm-isa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol
CC		=	cc
CFLAGS	=	-g -fsanitize=address -Wall -Wextra -Werror -Iminilibx

SRCDIR	=	./srcs
SRC 	=	aux_utils.c \
			fractol.c \
			fract_all.c \
			fract_utils.c \
			keys.c
			
SRCPATH	=	$(addprefix $(SRCDIR)/, $(SRC))

OBJDIR = objects
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCPATH))

FRACTOL	=	./includes
LIBMLX	=	./includes/minilibx_macos
LIBFT	=	./includes/libft
#MLX		=	-L$(LIBMLX)/ -lmlx -lXext -lX11 -lm -lz
MLX		=	-L$(LIBMLX)/ -lmlx -framework OpenGL -framework AppKit
LFT		=	-L$(LIBFT)/ -lft

INC		=	-I$(FRACTOL) -I$(LIBFT) -I$(LIBMLX)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBMLX)
	make -C $(LIBFT)
	make -C $(LIBMLX)
	$(CC) $(OBJS) $(CFLAGS) $(LFT) $(MLX) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	make -C $(LIBFT) clean
	make -C $(LIBMLX) clean
	rm -rf $(OBJDIR)

fclean:
	make -C $(LIBFT) fclean
	rm -rf $(OBJDIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

