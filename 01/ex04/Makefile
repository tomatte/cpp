# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 09:33:18 by dbrandao          #+#    #+#              #
#    Updated: 2023/09/07 19:07:15 by dbrandao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	notsed

SOURCES		=	main.cpp \

OBJ		=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
OBJ_DIR	=	objs

CC			=	c++ -std=c++98
CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -rf

$(OBJ_DIR)/%.o:	%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

test:
	./$(NAME) file1 "right" "here"
	./$(NAME) file2 "hate" "love"
	./$(NAME) file3 "three" ""

$(NAME):	$(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

$(OBJ_DIR):
	mkdir -p objs

clean:
	$(RM) $(OBJ_DIR)
	$(RM) file1.replace file2.replace file3.replace

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
