NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

SRC = srs/push_swap.c srs/commands.c srs/check_error.c\
		srs/sort_stack.c srs/algo.c srs/algo_under10.c\
		srs/algo_under100.c srs/algo_above100.c srs/check_double.c\
		srs/sort_method.c

libft = ./libft/libft.a

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	make -C libft
	@echo "'$^'"
	gcc $(CFLAGS) -o $@ $^ $(libft) 

%.o : %.c
	gcc $(CFLAGS) -o $@ -c $^

clean:
	rm -f $(OBJ)
	@make -C libft clean

fclean: clean
		rm -f $(NAME)
		@make -C libft fclean

re: fclean all