# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 00:17:54 by jasong            #+#    #+#              #
#    Updated: 2022/06/27 19:51:19 by woonchoi         ###   ########.fr        #
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
MLX_DIR = ./mlx/
MLX_LINUX_DIR = ./mlxlinux/

SRC_DIR = ./src/
PARSER_DIR = $(SRC_DIR)parser/
MLX_LOGIC_DIR = $(SRC_DIR)mlx_logic/


LIBRARIES = -L$(LIBFT_DIR) -L$(GNL_DIR)
INCLUDES = -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(INC_DIR) -I$(MLX_LINUX_DIR)

MLX_FLAG = -Lmlx -lmlx -framework OpenGL -framework AppKit
MLX_FLAG_LINUX = -L ./mlxlinux -lmlx -lXext -lX11

MAIN_SRCS = init_info.c \
			main.c \
			print_err.c \
			safety_free.c \
			test_util.c \

PARSER_SRCS =	check_arg.c \
				check_splitted.c \
				count_element.c \
				parser_list_util.c \
				parser_util.c \
				parser.c \
				set_color.c \
				set_element.c\
				set_texture.c \
				validate_file.c \
				validate_map_util.c \
				validate_map.c \

MLX_LOGIC_SRCS =	exit_hook.c \
					init_mlx.c \

MAIN_SRCDIR = $(addprefix $(SRC_DIR), $(MAIN_SRCS))
PARSER_SRCDIR = $(addprefix $(PARSER_DIR), $(PARSER_SRCS))
MLX_LOGIC_SRCDIR = $(addprefix $(MLX_LOGIC_DIR), $(MLX_LOGIC_SRCS))

SRCS = $(MAIN_SRCDIR) $(PARSER_SRCDIR) $(MLX_LOGIC_SRCDIR)
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(LIBFT) $(GNL) $(MLX_LINUX) $(OBJS)
	@echo $(COLOR_GREEN) "Compile object files completed!" $(COLOR_RESET)
	@$(CC) $(CFLAG) $(LIBRARIES) $(INCLUDES) $(OBJS) -o $(NAME) -lft -lgnl $(MLX_FLAG_LINUX) $(SAN_FLAG)
	@echo $(COLOR_GREEN) "Compile $(NAME) completed!" $(COLOR_RESET)

%.o: %.c
	@echo $(COLOR_GREEN) "Compiling...\t" $(COLOR_RESET) $(COLOR_YELLOW) $< $(COLOR_BLUE) $(LINE_CLEAR) $(COLOR_RESET)
	@$(CC) $(CFLAG) -c $(INCLUDES) -I$(MLX_DIR) $< -o $@

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR) all
	@echo $(COLOR_GREEN) "Compile 'libft.a' completed!" $(COLOR_RESET)

$(GNL):
	@$(MAKE) -s -C $(GNL_DIR) all
	@echo $(COLOR_GREEN) "Compile 'libgnl.a' completed!" $(COLOR_RESET)

$(MLX_LINUX):
	@$(MAKE) -s -C $(MLX_LINUX_DIR) all
	@echo $(COLOR_GREEN) "Compile 'libmlx.a' completed!" $(COLOR_RESET)

clean:
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(GNL_DIR) clean
	@rm -rf $(OBJS)
	@echo $(COLOR_RED) "'$(NAME)'s objective files are removed!" $(COLOR_RESET)

fclean:
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(GNL_DIR) fclean
	@$(MAKE) -s -C $(MLX_DIR) clean
	@rm -rf $(OBJS)
	@rm -rf $(NAME)
	@echo $(COLOR_RED) "Program '$(NAME)' has removed!" $(COLOR_RESET)

jasong: $(LIBFT) $(OBJS)
	@$(MAKE) -s -C $(GNL_DIR) all
	@echo $(COLOR_GREEN) "Compile 'libgnl.a' completed!" $(COLOR_RESET)
	@$(MAKE) -s -C $(MLX_DIR) all
	@echo $(COLOR_GREEN) "Compile 'libmlx.a' completed!" $(COLOR_RESET)
	@$(CC) $(CFLAG) $(LIBRARIES) -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(INC_DIR) -I$(MLX_DIR) $(OBJS) -o $(NAME) -lft -lgnl $(MLX_FLAG) $(SAN_FLAG)
	@echo $(COLOR_GREEN) "Compile $(NAME) completed!" $(COLOR_RESET)

re : fclean all

.PHONY : all clean fclean re debug
