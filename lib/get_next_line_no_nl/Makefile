# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/14 17:15:58 by itakumi           #+#    #+#              #
#    Updated: 2026/01/06 16:49:14 by itakumi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = get_next_line_no_nl.a

SRCS = get_next_line_no_nl.c get_next_line_no_nl_utils.c

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)


all: $(NAME)

re: fclean all

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

.PHONY: all re clean fclean
