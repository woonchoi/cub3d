# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 00:17:54 by jasong            #+#    #+#              #
#    Updated: 2022/06/25 15:19:29 by woonchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

COLOR_RED = "\x1b[31m" 
COLOR_GREEN = "\x1b[32m"
COLOR_YELLOW = "\x1b[33m"
COLOR_BLUE = "\x1b[34m"
COLOR_WHITE = "\x1b[37m"
COLOR_CYAN = "\x1b[36m"
COLOR_RESET = "\x1b[0m"
LINE_CLEAR = "\x1b[1A\x1b[M"

CC = clang
CFLAG = -Wall -Wextra -Werror
SAN_FLAG = -g3 -fsanitize=address
LIBFT_DIR = ./lib/libft/
LIBFT = $(LIBFT_DIR)libft.a
GNL_DIR = ./lib/get_next_line/
GNL = $(GNL_DIR)libgnl.a

INC_DIR = ./includes/
SRC_DIR = ./src/
MLX_DIR = ./mlx/

LIBRARIES = -L$(LIBFT_DIR) -L$(GNL_DIR)
INCLUDES = -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(INC_DIR)

MLX_FLAG = -Lmlx -lmlx -framework OpenGL -framework AppKit
MLX_FLAG_LINUX = -L ./mlx -lmlx -lXext -lX11

SRC = cub3d_map_parser.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(LIBFT) $(GNL) $(OBJS)
	@echo $(COLOR_GREEN) "Compile object files completed!" $(COLOR_RESET)
	@$(CC) $(CFLAG) $(LIBRARIES) $(INCLUDES) $(OBJS) -o $(NAME) -lft -lgnl
	@echo $(COLOR_GREEN) "Compile $(NAME) completed!" $(COLOR_RESET)

%.o: %.c
	@echo $(COLOR_GREEN) "Compiling...\t" $(COLOR_RESET) $(COLOR_YELLOW) $< $(COLOR_BLUE) $(LINE_CLEAR)
	@$(CC) $(CFLAG) -c $(INCLUDES) $< -o $@

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR) all
	@echo $(COLOR_GREEN) "Compile 'libft.a' completed!" $(COLOR_RESET)

$(GNL):
	@$(MAKE) -s -C $(GNL_DIR) all
	@echo $(COLOR_GREEN) "Compile 'libgnl.a' completed!" $(COLOR_RESET)

clean:
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(GNL_DIR) clean
	@rm -rf $(OBJS)
	@echo $(COLOR_RED) "'$(NAME)'s objective files are removed!" $(COLOR_RESET)

fclean:
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(GNL_DIR) fclean
	@rm -rf $(OBJS)
	@rm -rf $(NAME)
	@echo $(COLOR_RED) "Program '$(NAME)' has removed!" $(COLOR_RESET)

re : fclean all

.PHONY : all clean fclean re debug
