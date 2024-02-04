

NAME = minitalk

LIB = minitalk.h

FLAGS = -Wall -Werror -Wextra

CC = gcc

all: $(NAME)

$(NAME):	$(OBJ)
	make -C ./ft_printf
	gcc $(FLAGS) server.c ft_atoi.c ./ft_printf/libftprintf.a -o server 
	gcc $(FLAGS) client.c ft_atoi.c ./ft_printf/libftprintf.a -o client

clean:
	rm -f *.o	
	rm -f ./ft_printf/*.o

fclean: clean
	rm client
	rm server
	rm -f ./ft_printf/libftprintf.a

re: fclean all
