# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: natallia <natallia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 13:03:26 by nkhamich          #+#    #+#              #
#    Updated: 2024/12/15 12:04:19 by natallia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
SRC			= main.c utils.c \
				map_validation/map_checker.c map_validation/map_utils.c \
				map_validation/path_finder.c rendering/load_images.c \
				rendering/move_player.c rendering/utils.c
OBJ_DIR		= obj
OBJ			= $(SRC:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

MLX_LIB = $(MLX_DIR)/libmlx.a

ifeq ($(shell uname), Darwin)
	MLX_FLAGS = -framework OpenGL -framework AppKit
	MLX_DIR = ./mlx_mac
else
	MLX_FLAGS = -lX11 -lXext -lm
	MLX_DIR = ./mlx_linux
endif

all: $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "Object directory created for $(NAME)."

# $(NAME): $(OBJ) $(LIBFT)
# 	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
# 	@echo "$(NAME) executable created successfully."

$(NAME): $(OBJ) $(LIBFT) $(MLX_LIB)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -L$(MLX_DIR) -lmlx $(MLX_FLAGS) -o $(NAME)
	@echo "$(NAME) executable created successfully."

$(LIBFT):
	@make -C $(LIBFT_PATH) all

$(MLX_LIB):
	@make -C $(MLX_DIR)

bonus: all

clean:
	@make -C $(LIBFT_PATH) clean
	@make -C $(MLX_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "Object files cleaned for $(NAME)."

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@rm -rf $(NAME)
	@echo "Executable fully cleaned."

re: fclean all

.PHONY: all bonus clean fclean re libft
