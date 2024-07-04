# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 21:16:41 by mm-isa            #+#    #+#              #
#    Updated: 2024/07/04 05:29:27 by mm-isa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	fdf
CC		= 	cc
CFLAGS	= 	-g -Wall -Wextra -Werror -Iminilibx

SRCDIR	= 	srcs
OBJDIR	= 	objects

SRCS	= 	fdf.c \
			arg_handler.c \
			readmap.c \
			draw_map.c \
			map_utils1.c \
			map_utils2.c \
			mapmove.c \
			cleanup.c
			
SRCPATH	=	$(addprefix $(SRCDIR)/, $(SRCS))
OBJS	= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCPATH))

FDF		=	./includes/
LIBFT	= 	./includes/libft
LIBMLX	= 	./includes/minilibx_macos
MLX		= 	-L$(LIBMLX)/ -lmlx -framework OpenGL -framework Appkit
##MLX	= 	-Lincludes/minilibx-linux -lmlx -lXext -lX11 -lm -lz
LFT		=	-L$(LIBFT)/ -lft
INC		=	-I$(FDF) -I$(LIBFT) -I$(LIBMLX)

all			: $(NAME)

$(NAME)		: $(OBJS) $(FDF)/* $(LIBFT)/*.c $(LIBMLX)/*.c
		make -C $(LIBFT)
		make -C $(LIBMLX)
		$(CC) $(OBJS) $(CFLAGS) $(LFT) $(MLX) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
		$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJDIR)	:
		mkdir -p $(OBJDIR)

clean:
		make -C $(LIBFT) clean
		make -C $(LIBMLX) clean
		rm -rf $(OBJDIR)
fclean:	clean
		make -C $(LIBFT) fclean
		rm -f $(NAME)
	
re: fclean all

.PHONY:	all clean fclean re