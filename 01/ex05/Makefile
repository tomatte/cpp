# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 08:02:18 by dbrandao          #+#    #+#              #
#    Updated: 2023/09/07 08:20:45 by dbrandao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	harl

SOURCES		=	main.cpp \
				Harl.cpp \

OBJ		=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
OBJ_DIR	=	objs

CC			=	c++ -std=c++98
CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -rf

$(OBJ_DIR)/%.o:	%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)
	@./$(NAME)

$(NAME):	$(OBJ_DIR) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@

$(OBJ_DIR):
	@mkdir -p objs

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
