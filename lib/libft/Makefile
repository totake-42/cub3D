# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 22:13:28 by itakumi           #+#    #+#              #
#    Updated: 2025/12/19 07:34:01 by tnaito           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

FTS =   atoi\
        bzero\
        calloc\
        isalpha\
        isdigit\
        isalnum\
        isascii\
        isprint\
        itoa\
        memset\
        memcpy\
        memmove\
        memchr\
        memcmp\
        putchar_fd\
        putstr_fd\
        putnbr_fd\
        putendl_fd\
        split\
        strchr\
        strdup\
        striteri\
        strjoin\
        strlcat\
        strlcpy\
        strlen\
        strmapi\
        strncmp\
        strnstr\
        strrchr\
        strtrim\
        substr\
        toupper\
        tolower\

# BONUS_FTS =\
#         lstadd_back\
#         lstadd_front\
#         lstclear\
#         lstdelone\
#         lstiter\
#         lstlast\
#         lstmap\
#         lstnew\
#         lstsize\

SRCS = ${addprefix ft_, ${addsuffix .c, $(FTS)}}
OBJS = $(SRCS:.c=.o)
# BONUS_SRCS = ${addprefix ft_, ${addsuffix .c, $(BONUS_FTS)}}
# BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# ifdef WITH_BONUS
# OBJS += $(BONUS_OBJS)
# endif

$(NAME): $(OBJS)
	ar r $(NAME) $(OBJS)
	ranlib $(NAME)

# bonus:
# 	make WITH_BONUS=1

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re
