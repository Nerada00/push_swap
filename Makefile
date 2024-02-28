SRCS = src/main.c \
       src/utils.c \
	   src/parsing.c \
	   src/ft_split.c \
	   src/ft_atoi.c \
	   src/grab.c \
	   src/move_swap.c \
	   src/move_rotate.c \
	   src/move_push.c \
	   src/sort.c \
	   src/cost.c \
	   src/sort_tool.c \
	   src/printf/ft_printf.c \
	   src/printf/ft_printf_fonction.c \

OBJS = $(SRCS:.c=.o)

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f

all: $(NAME)

##############   barre de chargement    ##############

	@echo -n "\033[32m [EXECUTION] \033[0m: Compiling push_swap... "
	@total_iterations=40; \
	i=0; \
	while [ $$i -lt $$total_iterations ]; do \
		sleep 0.01; \
		printf "\033[32m▇\033[0m"; \
		i=$$((i + 1)); \
	done

#header nom du programme
	
	@echo
	@echo "\033[36;5m =========== Compilation completed successfully.=========== \033[0m"
	@echo 
	@echo "\033[36m  ██████╗ ██╗   ██╗███████╗██╗  ██╗    ███████╗██╗    ██╗ █████╗ ██████╗  \033[0m"
	@echo "\033[36m  ██╔══██╗██║   ██║██╔════╝██║  ██║    ██╔════╝██║    ██║██╔══██╗██╔══██╗  \033[0m"
	@echo "\033[36m  ██████╔╝██║   ██║███████╗███████║    ███████╗██║ █╗ ██║███████║██████╔╝  \033[0m"
	@echo "\033[36m  ██╔═══╝ ██║   ██║╚════██║██╔══██║    ╚════██║██║███╗██║██╔══██║██╔═══╝   \033[0m"
	@echo "\033[36m  ██║     ╚██████╔╝███████║██║  ██║    ███████║╚███╔███╔╝██║  ██║██║       \033[0m"
	@echo "\033[34m  ╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝    ╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     \033[0m"
	@echo
	
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)


%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@


clean:
	@$(RM) $(OBJS)

#header du clean
	@echo
	@echo "\033[35;5m =========== OBJ was removed.=========== \033[0m"
	@echo
	@echo "\033[35m ██████╗ ███████╗███╗   ███╗ ██████╗ ██╗   ██╗███████╗██████╗ \033[0m"
	@echo "\033[35m ██╔══██╗██╔════╝████╗ ████║██╔═══██╗██║   ██║██╔════╝██╔══██╗ \033[0m"
	@echo "\033[35m ██████╔╝█████╗  ██╔████╔██║██║   ██║██║   ██║█████╗  ██║  ██║ \033[0m"
	@echo "\033[35m ██╔══██╗██╔══╝  ██║╚██╔╝██║██║   ██║╚██╗ ██╔╝██╔══╝  ██║  ██║ \033[0m"
	@echo "\033[35m ██║  ██║███████╗██║ ╚═╝ ██║╚██████╔╝ ╚████╔╝ ███████╗██████╔╝ \033[0m"
	@echo "\033[35m ╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝ ╚═════╝   ╚═══╝  ╚══════╝╚═════╝  \033[0m"
	@echo

fclean:
	@$(RM) $(OBJS)
	@$(RM) $(NAME)

#header du fclean
	@echo
	@echo "\033[31;5m =========== All was removed.=========== \033[0m"
	@echo
	@echo "\033[31m ██████╗ ███████╗███╗   ███╗ ██████╗ ██╗   ██╗███████╗██████╗ \033[0m"
	@echo "\033[31m ██╔══██╗██╔════╝████╗ ████║██╔═══██╗██║   ██║██╔════╝██╔══██╗ \033[0m"
	@echo "\033[31m ██████╔╝█████╗  ██╔████╔██║██║   ██║██║   ██║█████╗  ██║  ██║ \033[0m"
	@echo "\033[31m ██╔══██╗██╔══╝  ██║╚██╔╝██║██║   ██║╚██╗ ██╔╝██╔══╝  ██║  ██║ \033[0m"
	@echo "\033[31m ██║  ██║███████╗██║ ╚═╝ ██║╚██████╔╝ ╚████╔╝ ███████╗██████╔╝ \033[0m"
	@echo "\033[31m ╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝ ╚═════╝   ╚═══╝  ╚══════╝╚═════╝  \033[0m"
	@echo

re: fclean all

.PHONY: clean fclean all re

