# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 22:16:53 by jasong            #+#    #+#              #
#    Updated: 2022/03/04 22:19:50 by jasong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAG = -Wall -Wextra -Werror

NAME = libgnl.a

SRC = get_next_line.c get_next_line_utils.c
B_SRC = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJ = $(SRC:.c=.o)
B_OBJ = $(B_SRC:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

$(NAME) : $(OBJ)
	ar -cr $@ $^

clean :
	@rm -f $(OBJ) $(B_OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

bonus : $(B_OBJ)
	ar -cr $(NAME) $^

.PHONY : all clean fclean re bonus
