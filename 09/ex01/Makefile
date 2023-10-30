RED			=	"\033[0;31m"
GREEN		=	"\033[0;32m"
BLUE		=	"\033[0;34m"
NC			=	"\033[0m"

NAME		=	RPN

SOURCES		=	main.cpp \

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

#compile without -Werror
nf: CFLAGS = -Wall -Wextra
nf: all
nfr: fclean nf

.PHONY:	all clean fclean re
