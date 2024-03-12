# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 23:50:19 by mm-isa            #+#    #+#              #
#    Updated: 2024/03/13 01:07:37 by mm-isa           ###   ########.fr        #
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
LIBDIR = lib_ft
LIB = lib_ft.a

all: $(INFILE) $(OUTFILE) $(LIBDIR)/$(LIB) $(EXEC)

bonus: $(INFILE) $(OUTFILE) $(LIBDIR)/$(LIB) $(BONUS_OBJ)
	$(CC) $(CFLAGS) -o $(BONUS_EXEC) $(BONUS_OBJ) -L$(LIBDIR) -l_ft

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) -L$(LIBDIR) -l_ft

$(BONUS_EXEC): $(BONUS_OBJ)
	$(CC) $(CFLAGS) -o $(BONUS_EXEC) $(BONUS_OBJ) -L$(LIBDIR) -l_ft

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
