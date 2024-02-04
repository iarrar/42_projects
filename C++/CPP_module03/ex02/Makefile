# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 13:48:26 by iarrar            #+#    #+#              #
#    Updated: 2024/01/30 18:05:43 by iarrar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ClapTrap.class.cpp ScavTrap.class.cpp FragTrap.class.cpp main.cpp
CXX = c++
OBJ = $(SRC:.cpp=.o)
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ScavTrap

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re