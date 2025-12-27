# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/26 10:45:00 by itakumi           #+#    #+#              #
#    Updated: 2025/12/27 13:11:18 by itakumi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

override	NAME	= cub3D

override	CC		= cc
override	CFLAGS	= -Wall -Werror -Wextra

M_FLAG				= -lm
# Linux
MLX_FLAGS			= -L $(DIR_MLX) -lmlx -lXext -lX11

override DIR_SRCS	= src
override DIR_INCS	= include
override DIR_OBJS	= build
override DIR_LIBS	= lib
override DIR_MLX	= lib/minilibx

SRCS				= $(shell find $(DIR_SRCS) -type f -name "*.c")

INCS				= -I $(DIR_INCS) $(foreach PATH_LIB,$(PATH_LIBS),-I $(PATH_LIB))
OBJS				= $(SRCS:%.c=$(DIR_OBJS)/%.o)
LIBS				= libft
						
PATH_LIBS			= $(foreach LIB,$(LIBS),$(DIR_LIBS)/$(LIBS))
ARCH_LIBS			= $(foreach PATH_LIB,$(PATH_LIBS),$(PATH_LIB)/$(notdir $(PATH_LIB)).a)

### minilibx ###
LIB_MLX				= $(DIR_MLX)/libmlx.a

### Default Rules ###

.DEFAULT_GOAL		:= all

$(NAME): $(ARCH_LIBS) $(LIB_MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(ARCH_LIBS) $(MLX_FLAGS) $(M_FLAG) -o $@

$(DIR_OBJS)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@
	
all: $(NAME)

bonus: all

clean: $(ARCH_LIBS:%=%__clean)
	$(MAKE) clean -C $(DIR_MLX)
	rm -rf $(DIR_OBJS)
	
fclean: clean $(ARCH_LIBS:%=%__fclean)
	rm -f $(NAME)

re: $(ARCH_LIBS:%=%__re)
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
.PHONY: bonus

### Library Rules ###
%.a:
	$(MAKE) all -C $(dir $@)

$(LIB_MLX):
	@if [ ! -d $(DIR_MLX) ]; then \
		printf "\033[31mMiniLibX directory $(DIR_MLX) not found.\033[0m\n"; \
		printf "Do you want to clone it? [y/n] "; \
		read -r ans; \
		if [ "$$ans" = "y" ] || [ "$$ans" = "Y" ] || [ "$$ans" = "yes" ]; then \
			git clone https://github.com/42Paris/minilibx-linux.git "$(DIR_MLX)"; \
		else \
			echo "Skipping MiniLibX clone, build may fail."; \
			exit 1; \
		fi; \
	fi
	$(MAKE) all -C $(DIR_MLX)
	
%.a__clean:
	$(MAKE) clean -C $(dir $@)
	
%.a__fclean:
	$(MAKE) fclean -C $(dir $@)

%.a__re:
	$(MAKE) re -C $(dir $@)

### Utils Rules ###
SRCS_LIST			= $(shell find $(DIR_SRCS) -type f -name "*.c")

print_sourcefiles:
	@$(foreach SRC,$(SRCS_LIST),echo '$(SRC:$(DIR_SRCS)/%.c=%.c\\)';)

norm:
	@norminette | grep 'Error'

.PHONY: print_sourcefiles norm

