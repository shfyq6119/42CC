NAME = philo_bonus

SRCS = philo_bonus.c error_bonus.c inits_bonus.c utils_bonus.c sim_bonus.c

OBJS = $(SRCS:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g
AR = ar rc
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) -c $(SRCS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
