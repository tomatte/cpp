# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-souz <gde-souz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 16:42:26 by gde-souz          #+#    #+#              #
#    Updated: 2023/12/06 17:29:55 by gde-souz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the executable
NAME = fdf

# Compilation flags
CFLAGS = -Wall -Wextra -Werror
INCLUDES = ./includes

# Libft
PATH_LIBFT = ./libft/
LIBFT = $(addprefix $(PATH_LIBFT), libft.a)

# GNL
PATH_GNL = ./gnl/
GNL = $(addprefix $(PATH_GNL), gnl.a)

# MLX
MLX_BUILD = ./MLX42
MLX = ./MLX42/build/libmlx42.a
MLX_FLAGS = -IMLX42/include/MLX42 -ldl -lglfw -pthread -lm -Ofast -flto

# fdf
SRC = ./src/mandatory/main.c \
		./src/mandatory/init.c \
		./src/mandatory/read_file.c \
		./src/mandatory/draw.c \
		./src/mandatory/draw_utils.c \
		./src/mandatory/controls.c \
		./src/mandatory/calc.c \
		./src/mandatory/color.c

SRC_BONUS = ./src/bonus/main_bonus.c \
			./src/bonus/init_bonus.c \
			./src/bonus/read_file_bonus.c \
			./src/bonus/draw_bonus.c \
			./src/bonus/draw_utils_bonus.c \
			./src/bonus/controls_bonus.c \
			./src/bonus/calc_bonus.c \
			./src/bonus/color_bonus.c
# Objects
OBJ_PATH = ./build/
OBJ = $(addprefix $(OBJ_PATH), $(notdir $(SRC:.c=.o)))
OBJ_PATH_BONUS = ./build_bonus/
OBJ_BONUS = $(addprefix $(OBJ_PATH_BONUS), $(notdir $(SRC_BONUS:.c=.o)))

# Color codes of output on terminal
PURPLE = \033[1;35m
WHITE = \033[1;37m
CYAN= \033[0;36m

# Default target to compile the mandatory part
all: $(NAME)

# Target to build the mandatory part
$(NAME): $(MLX) $(LIBFT) $(GNL) $(OBJ)
	@rm -f $(OBJ_BONUS)
	@rm -rf $(OBJ_PATH_BONUS)
	@cp $(LIBFT) $(NAME)
	@cp $(GNL) $(NAME)
	$(CC) $(OBJ) $(LIBFT) $(GNL) $(MLX) -L$(PATH_LIBFT) -L$(PATH_GNL) -lft $(MLX_FLAGS) -o $(NAME)
	@echo "$(PURPLE)--------------------------------------------------"
	@echo "$(PURPLE)The [$(CYAN)FDF$(PURPLE)] has been compiled! 🤠"
	@echo "$(PURPLE)--------------------------------------------------"

# Target to build the bonus part
bonus: $(MLX) $(LIBFT) $(GNL) $(OBJ_BONUS)
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)
	@cp $(LIBFT) $(NAME)
	@cp $(GNL) $(NAME)
	$(CC) $(OBJ_BONUS) $(LIBFT) $(GNL) $(MLX) -L$(PATH_LIBFT) -L$(PATH_GNL) -lft $(MLX_FLAGS) -o $(NAME)
	@echo "$(PURPLE)--------------------------------------------------"
	@echo "$(PURPLE)The [$(CYAN)FDF_BONUS$(PURPLE)] has been compiled! 🤠"
	@echo "$(PURPLE)--------------------------------------------------"

# Builds dependencies
$(LIBFT):
	@make -C $(PATH_LIBFT)

$(GNL):
	@make -C $(PATH_GNL)

$(MLX):
ifeq ($(wildcard $(MLX_BUILD)/build/ ), )
	@cd ./MLX42/ && cmake -B build
	@cd ./MLX42/ && cmake --build build -j4
endif

# Builds mandatory object files
$(OBJ_PATH)%.o: src/mandatory/%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(dir $@)

# Builds bonus object files
$(OBJ_PATH_BONUS)%.o: src/bonus/%.c
	@mkdir -p $(OBJ_PATH_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(dir $@)

# Cleans object files and dependencies
clean:
	@rm -f $(OBJ)
	@rm -f $(OBJ_BONUS)
	@rm -rf $(OBJ_PATH)
	@rm -rf $(OBJ_PATH_BONUS)
	@make clean -C $(PATH_LIBFT)
	@make clean -C $(PATH_GNL)
	@echo "$(WHITE)-----------------------------------"
	@echo "$(WHITE)    Object files were cleaned!"
	@echo "$(WHITE)-----------------------------------"

# Cleans the executable file and pre-compiled header
fclean: clean
	@echo "$(WHITE)-----------------------------------"
	@echo "$(WHITE)        Cleaning all... 🧹"
	@echo "$(WHITE)-----------------------------------"
	@rm -f $(NAME)
	@rm -f $(HD)*.gch
	@make fclean -C $(PATH_LIBFT)
	@make fclean -C $(PATH_GNL)
	@echo "$(WHITE)-----------------------------------"
	@echo "$(WHITE)    ✨ Cleaning complete! ✨"
	@echo "$(WHITE)-----------------------------------"

# Cleans everything generated by the Makefile and rebuild it all
re: fclean all

# Phony targets
.PHONY: all bonus clean fclean re $(MLX_BUILD)