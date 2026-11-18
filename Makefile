# **************************************************************************** #
#                                                                              #
#                                                        :::      ::::::::     #
#    Makefile                                          :+:      :+:    :+:     #
#                                                    +:+ +:+         +:+       #
#    By: paziehen <paziehen@student.42vienna.com>  #+#  +:+       +#+          #
#                                                +#+#+#+#+#+   +#+             #
#    Created: 2026/11/18 20:46:58 by paziehen         #+#    #+#               #
#    Updated: 2026/11/18 20:48:29 by paziehen        ###   ########.fr         #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_printf_formats.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	 ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	 $(CC) $(CFLAGS) -c $< -o $@

clean:
	 rm -f $(OBJS)

fclean: clean
	 rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
