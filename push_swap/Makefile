
NAME = push_swap

FLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a

FTPRINTF = ./ft_printf/libftprintf.a

SRCS = push_swap.c initialisation.c manipulations.c check.c desinit.c radix.c check_bis.c mini_sort.c initialisation_bis.c mini_sort_bis.c

CC = gcc

all: $(NAME)

$(NAME):	
	$(CC) $(FLAGS) $(SRCS) $(LIBFT) $(FTPRINTF) -o $(NAME)
	
clean:
	rm -f *.o
	make clean -C ./libft
	make clean -C ./ft_printf

fclean: clean
	rm $(NAME)

re: fclean all
