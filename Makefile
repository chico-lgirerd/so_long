# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 16:02:03 by lgirerd           #+#    #+#              #
#    Updated: 2025/03/05 12:00:51 by lgirerd          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME    	= so_long
CC      	= cc
CFLAGS  	= -Wall -Wextra -Werror
LIBFLAGS 	= -lm
MLXFLAGS 	= -I/usr/include -Imlx
LINKFLAGS 	= -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
LIBFT		= ./libft/libft.a
INC			= -I$(LIBFT_DIR) -I$(HDR_DIR) -I$(MLX_DIR)
HDR			= so_long.h
HDR_DIR		= include
LIBFT_DIR	= libft/include
LIBFT_HDR	= libft.h
MLX_DIR		= mlx
MLX_HDR		= mlx.h

############################# SOURCES #############################

SRCS_DIR 	= srcs/
SRCS    	= $(SRCS_DIR)map_checker_core.c \
			  $(SRCS_DIR)utils.c \
			  $(SRCS_DIR)init.c \
			  $(SRCS_DIR)map_utils.c \
			  $(SRCS_DIR)so_long.c \
			  $(SRCS_DIR)map_checker_fill.c \
			  $(SRCS_DIR)draw.c \
			  $(SRCS_DIR)load.c \
			  $(SRCS_DIR)move.c \
			  $(SRCS_DIR)player.c

############################# DIRECTORIES ##############################

OBJS_DIR = srcs/.objs/
OBJS    = $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)
DEPS := $(OBJS:.o=.d)

############################# RULES ##############################

all:$(LIBFT) $(NAME)

$(LIBFT): $(wildcard libft/srcs/**/*.c) $(LIBFT_DIR)/$(LIBFT_HDR)
	make -C ./libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(LINKFLAGS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(addprefix $(HDR_DIR)/, $(HDR)) $(MLX_DIR)/$(MLX_HDR)
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INC) -MMD -c $< -o $@ $(MLXFLAGS)

clean:
	make clean -C libft
	rm -rf $(OBJS_DIR)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

norm:
	@norminette srcs | grep Error || true
	@norminette include | grep Error || true
	@norminette libft | grep Error || true 

-include $(DEPS)

.PHONY: all clean fclean re norm
