# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/15 22:08:35 by jasong            #+#    #+#              #
#    Updated: 2022/03/04 22:43:06 by jasong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

LFT_DIR = ../libft/
LIBFT = libft.a
NAME = libftprintf.a

SOURCES = ft_printf.c do_printf.c process_one.c process_two.c utils.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJECTS)
	@make -s -C $(LFT_DIR) bonus
	@cp $(LFT_DIR)$(LIBFT) $(NAME)
	@ar -cr $@ $^

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
