# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 14:24:00 by dbrandao          #+#    #+#              #
#    Updated: 2023/10/05 15:25:51 by dbrandao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED			=	"\033[0;31m"
GREEN		=	"\033[0;32m"
NC			=	"\033[0m"

NAME		=	animals

SOURCES		=	main.cpp \
				Animal.cpp \
				Dog.cpp \
				Cat.cpp \
				WrongAnimal.cpp \
				WrongCat.cpp \

OBJ		=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
OBJ_DIR	=	objs

CC			=	c++ -std=c++98
CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -rf

$(OBJ_DIR)/%.o:	%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@
	@echo "\n"Executable: $(GREEN) $(NAME) $(NC)

$(OBJ_DIR):
	mkdir -p objs

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
