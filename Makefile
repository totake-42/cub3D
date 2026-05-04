# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/26 10:45:00 by itakumi           #+#    #+#              #
#    Updated: 2026/05/04 19:13:32 by tigarashi        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

override	NAME	= cub3D

override	CC		= cc
override	CFLAGS	= -Wall -Werror -Wextra

M_FLAG				= -lm
# Linux
MLX_FLAGS			= -L $(DIR_MLX) -lmlx -lXext -lX11

# Mandatory
M_DIR_SRCS			= mandatory/src
M_DIR_INCS			= mandatory/include
M_DIR_OBJS			= mandatory/build

# Bonus
B_DIR_SRCS			= bonus/src
B_DIR_INCS			= bonus/include
B_DIR_OBJS			= bonus/build

DIR_LIBS			= lib
DIR_MLX				= lib/minilibx

# Mandatory sources
M_SRCS				= game/dda.c\
					game/draw_column.c\
					game/game_loop.c\
					game/raycasting.c\
					game/render.c\
					game/rotate.c\
					game/event_handlers.c\
					game/check_collision.c\
					game/movement.c\
					init/init_player.c\
					init/init_textures.c\
					init/init_view.c\
					init/validate_textures.c\
					parse/load_map/validate_extension.c\
					parse/load_map/load_input_file.c\
					parse/parse_grid/parse_grid.c\
					parse/parse_grid/validate_characters.c\
					parse/parse_grid/validate_player.c\
					parse/parse_grid/validate_walls.c\
					parse/parse_identifier/parse_identifier_utils.c\
					parse/parse_identifier/set_identifier.c\
					parse/parse_identifier/set_identifier_utils.c\
					parse/parse_identifier/parse_identifiers.c\
					parse/parse_map.c\
					parse/parse_utils.c\
					utils/free_array.c\
					utils/free_map.c\
					utils/free_textures.c\
					utils/free_view.c\
					utils/ft_strequal.c\
					utils/ft_strndup.c\
					utils/ft_isspace.c\
					utils/print_error.c\
					main.c

# Bonus sources
B_SRCS				= game/check_collision_bonus.c\
					game/dda_bonus.c\
					game/draw_column_bonus.c\
					game/event_handlers_bonus.c\
					game/game_loop_bonus.c\
					game/movement_bonus.c\
					game/raycasting_bonus.c\
					game/render_bonus.c\
					game/rotate_bonus.c\
					init/init_player_bonus.c\
					init/init_textures_bonus.c\
					init/init_view_bonus.c\
					init/validate_textures_bonus.c\
					parse/load_map/load_input_file_bonus.c\
					parse/load_map/validate_extension_bonus.c\
					parse/parse_grid/parse_grid_bonus.c\
					parse/parse_grid/validate_characters_bonus.c\
					parse/parse_grid/validate_player_bonus.c\
					parse/parse_grid/validate_walls_bonus.c\
					parse/parse_identifier/parse_identifier_utils_bonus.c\
					parse/parse_identifier/parse_identifiers_bonus.c\
					parse/parse_identifier/set_identifier_bonus.c\
					parse/parse_identifier/set_identifier_utils_bonus.c\
					parse/parse_map_bonus.c\
					parse/parse_utils_bonus.c\
					utils/free_array_bonus.c\
					utils/free_map_bonus.c\
					utils/free_textures_bonus.c\
					utils/free_view_bonus.c\
					utils/ft_strequal_bonus.c\
					utils/ft_strndup_bonus.c\
					utils/ft_isspace_bonus.c\
					utils/print_error_bonus.c\
					main_bonus.c

M_INCS				= -I $(M_DIR_INCS) $(foreach PATH_LIB,$(PATH_LIBS),-I $(PATH_LIB))
M_INCS				+= -I $(DIR_MLX)

B_INCS				= -I $(B_DIR_INCS) $(foreach PATH_LIB,$(PATH_LIBS),-I $(PATH_LIB))
B_INCS				+= -I $(DIR_MLX)

OBJS 				= $(M_OBJS)
M_OBJS				= $(M_SRCS:%.c=$(M_DIR_OBJS)/%.o)
B_OBJS				= $(B_SRCS:%.c=$(B_DIR_OBJS)/%.o)
LIBS				= libft get_next_line get_next_line_no_nl

PATH_LIBS			= $(foreach LIB,$(LIBS),$(DIR_LIBS)/$(LIB))
ARCH_LIBS			= $(foreach PATH_LIB,$(PATH_LIBS),$(PATH_LIB)/$(notdir $(PATH_LIB)).a)

### minilibx ###
LIB_MLX				= $(DIR_MLX)/libmlx.a

BONUS_FLAGS		= 0
ifeq ($(BONUS_FLAGS), 1)
	OBJS = $(B_OBJS)
endif

### Default Rules ###
.DEFAULT_GOAL		:= all

all: $(NAME)

$(NAME): $(ARCH_LIBS) $(LIB_MLX) $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(ARCH_LIBS) $(MLX_FLAGS) $(M_FLAG) -o $(NAME)

bonus:
	$(MAKE) BONUS_FLAGS=1 all

$(M_DIR_OBJS)/%.o: $(M_DIR_SRCS)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(M_INCS) -c $< -o $@

$(B_DIR_OBJS)/%.o: $(B_DIR_SRCS)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(B_INCS) -c $< -o $@

clean: $(ARCH_LIBS:%=%__clean)
	$(MAKE) clean -C $(DIR_MLX)
	rm -rf $(M_DIR_OBJS)
	rm -rf $(B_DIR_OBJS)

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
M_SRCS_LIST			= $(shell find $(M_DIR_SRCS) -type f -name "*.c")
B_SRCS_LIST			= $(shell find $(B_DIR_SRCS) -type f -name "*.c")

print_sourcefiles:
	@echo "=== Mandatory Sources ==="
	@$(foreach SRC,$(M_SRCS_LIST),echo '$(SRC:$(M_DIR_SRCS)/%.c=%.c\\)';)
	@echo ""
	@echo "=== Bonus Sources ==="
	@$(foreach SRC,$(B_SRCS_LIST),echo '$(SRC:$(B_DIR_SRCS)/%.c=%.c\\)';)

norm:
	@norminette mandatory/src mandatory/include bonus/src bonus/include | grep 'Error'

.PHONY: print_sourcefiles norm

