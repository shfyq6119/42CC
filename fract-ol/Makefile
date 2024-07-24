# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/16 01:33:24 by mm-isa            #+#    #+#              #
#    Updated: 2024/07/02 18:41:00 by mm-isa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol
CC		=	cc
CFLAGS	=	-g -Wall -Wextra -Werror -Iminilibx

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
LIBMLX	=	./includes/minilibx-linux
LIBFT	=	./includes/libft
MLX		=	-L$(LIBMLX)/ -lmlx -lXext -lX11 -lm -lz
#MLX		=	-L$(LIMBLX)/ -lmlx -framework OpenGL -framework AppKit
LFT		=	-L$(LIBFT)/ -lft

INC		=	-I$(FRACTOL) -I$(LIBFT) -I$(LIBMLX)

MLX_URL		=	git@github.com:42Paris/minilibx-linux.git
MLX_REPO	=	$(LIBMLX)

all: $(NAME)

$(NAME): $(MLX_REPO) $(FRACTOL)/* $(OBJS)
	make -C $(LIBFT)
	make -C $(LIBMLX)
	$(CC) $(OBJS) $(CFLAGS) $(LFT) $(MLX) -o $(NAME)
	
$(MLX_REPO):
	@if [ ! -d "$(MLX_REPO)" ]; then \
		echo "Cloning repository into $(MLX_REPO)..."; \
		git clone $(MLX_URL) $(MLX_REPO); \
	fi

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)
	make -C $(LIBFT) clean
	make -C $(LIBMLX) clean
	rm -rf $(LIBMLX)

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean
re: fclean all

.PHONY: all clean fclean re

