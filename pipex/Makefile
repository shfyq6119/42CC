# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 23:50:19 by mm-isa            #+#    #+#              #
#    Updated: 2023/09/23 18:17:42 by mm-isa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
SRC = pipex.c pipex_toolkit.c
BONUS_SRC = pipex_bonus.c pipex_utils.c pipex_bonus_utils.c
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
EXEC = pipex
BONUS_EXEC = pipex_bonus
INFILE = infile
OUTFILE = outfile
LIBDIR = libft
LIB = libft.a

all: $(INFILE) $(OUTFILE) $(LIBDIR)/$(LIB) $(EXEC)

bonus: $(INFILE) $(OUTFILE) $(LIBDIR)/$(LIB) $(BONUS_OBJ)
	$(CC) $(CFLAGS) -o $(BONUS_EXEC) $(BONUS_OBJ) -L$(LIBDIR)/libft -lft

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) -L$(LIBDIR)/ -lft

$(BONUS_EXEC): $(BONUS_OBJ)
	$(CC) $(CFLAGS) -o $(BONUS_EXEC) $(BONUS_OBJ) -L$(LIBDIR)/libft -lft

%.o: %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

$(INFILE):
	touch $(INFILE)

$(OUTFILE):
	touch $(OUTFILE)

$(LIBDIR)/$(LIB):
	$(MAKE) -C $(LIBDIR)
	cp $(LIBDIR)/$(LIB) .

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	$(MAKE) -C $(LIBDIR) clean

fclean: clean
	rm -f $(EXEC) $(BONUS_EXEC) $(INFILE) $(OUTFILE) $(LIB)
	$(MAKE) -C $(LIBDIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
