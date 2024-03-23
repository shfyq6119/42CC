# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 23:50:19 by mm-isa            #+#    #+#              #
#    Updated: 2024/03/20 22:58:48 by mm-isa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
SRC = pipex.c pipex_toolkit.c
OBJ = $(SRC:.c=.o)
EXEC = pipex
INFILE = infile
OUTFILE = outfile
LIBDIR = lib_ft
LIB = lib_ft.a

all: $(INFILE) $(OUTFILE) $(LIBDIR)/$(LIB) $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) -L$(LIBDIR) -l_ft

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
	rm -f $(OBJ)
	$(MAKE) -C $(LIBDIR) clean

fclean: clean
	rm -f $(EXEC) $(INFILE) $(OUTFILE) $(LIB)
	$(MAKE) -C $(LIBDIR) fclean

re: fclean all

.PHONY: all clean fclean re
