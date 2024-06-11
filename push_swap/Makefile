# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mm-isa <marvin@42.fr> 			            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/11 10:33:46 by mm-isa            #+#    #+#              #
#    Updated: 2023/06/11 19:14:06 by mm-isa    	      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = push_swap
CC = cc

DLFLAGS = -O3 -g3 -L
CFLAGS = -Wall -Wextra -Werror -g

LIBFT = ./includes/libft
LIBS = ./includes
SRC_DIR = ./srcs
FILES = push_swap.c \
		flag_off.c \
		ft_stack_util.c	\
		rotate_module.c \
		stack_parse.c \
		push_module.c \
		restore_module.c \
		revrot_module.c \
		rotcost_utils.c \
		rotcost_utils_2.c \
		sort_parse.c \
		sort_rotcost.c \
		tiny.c

OBJ_DIR = objects

OBJ = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

RM = rm -f

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(LIBS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	$(CC) $(OBJ) $(CFLAGS) $(DLFLAGS) $(LIBFT)/ -lft -o $(NAME)

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus re_bonus
