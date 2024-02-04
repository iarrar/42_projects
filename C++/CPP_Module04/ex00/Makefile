# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 16:50:54 by iarrar            #+#    #+#              #
#    Updated: 2024/01/31 16:53:22 by iarrar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = Animal.class.cpp Cat.class.cpp Dog.class.cpp WrongAnimal.class.cpp WrongCat.class.cpp main.cpp
CXX = c++
OBJ = $(SRC:.cpp=.o)
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Animal

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re