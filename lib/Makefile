# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 16:32:50 by jasong            #+#    #+#              #
#    Updated: 2022/06/25 14:51:48 by woonchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAG = -Wall -Wextra -Werror
LFT_FLAG = -Llibft -lft

NAME = libjasong.a

GNL_DIR = ./get_next_line/
LFT_DIR = ./libft/

LIBFT = $(LFT_DIR)libft.a
GNL = $(GNL_DIR)libgnl.a

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

$(NAME) : $(LIBFT) $(GNL)
	libtool -static -o $@ $^
	echo "Now you can use libjasong.a !!"

$(LIBFT) : 
	@echo "Making libft ..."
	@make -s -C ./libft bonus
	@echo "Making libft done !"

$(GNL) : 
	@echo "Making gnl ..."
	@make -s -C ./get_next_line all
	@echo "Making gnl done !"

clean :
	@make -C $(LFT_DIR) clean
	@make -C $(GNL_DIR) clean
	@rm -f $(GNL_OBJ)

fclean : clean
	@make -C $(LFT_DIR) fclean
	@make -C $(GNL_DIR) fclean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
