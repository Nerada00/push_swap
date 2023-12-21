SRCS = main.c \
       utils.c \
	   parsing.c \
	   

OBJS = $(SRCS:.c=.o)

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f

all: ${NAME}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(L_FLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re

