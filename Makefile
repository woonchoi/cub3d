# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 00:17:54 by jasong            #+#    #+#              #
#    Updated: 2022/06/24 20:49:44 by jasong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAG = -Wall -Wextra -Werror

NAME = cub3d

INC_DIR = ./inc/
SRC_DIR = ./src/
MLX_DIR = ./mlx/
LIB_DIR = ./lib/

MLX_FLAG = -Lmlx -lmlx -framework OpenGL -framework AppKit
LIB_FLAG = -Llib -ljasong
INC_FLAG = -I$(INC_DIR)

SAN_FLAG = -g3 -fsanitize=address

SRC = $(addprefix $(SRC_DIR), 
		)
OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $< $(INC_FLAG) -o $@

$(NAME) : $(OBJ)
	@echo "Making library ..."
	@make -s -C $(LIB_DIR) all
	@echo "Making mlx library ..."
	@make -s -C $(MLX_DIR) all
	$(CC) $(CFLAG) $^ -o $@ $(INC_FLAG) $(MLX_FLAG) $(LIB_FLAG)

clean : 
	@make -C $(LIB_DIR) clean
	@make -s -C $(MLX_DIR) clean
	@rm -f $(OBJ)

fclean : clean
	@make -C $(LIB_DIR) fclean
	@rm -f $(NAME)

re : fclean all

debug :
	@echo "DEBUG MODE"
	@make -s -C $(LIB_DIR) all
	@make -s -C $(MLX_DIR) all
	$(CC) $(CFLAG) $(SAN_FLAG) $(SRC) -o $@ $(INC_FLAG) $(MLX_FLAG) $(LIB_FLAG)
dclean :
	@echo "debug outfile removed"
	@rm -f debug
	@rm -rf debug.dSYM

.PHONY : all clean fclean re debug
