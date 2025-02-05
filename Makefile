# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 16:02:03 by lgirerd           #+#    #+#              #
#    Updated: 2025/02/05 13:48:37 by lgirerd          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME    = so_long
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
LIBFLAGS = -lm
LIBFT	= ./libft/libft.a

############################# SOURCES #############################

SRCS_DIR = srcs/
SRCS    = $(addprefix $(SRCS_DIR), \
			)

############################# DIRECTORIES ##############################

OBJS_DIR = srcs/.objs/
OBJS    = $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)
DEPS := $(OBJS:.o=.d)

############################# RULES ##############################

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C ./libft

$(NAME): $(OBJS) Makefile
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(LIBFLAGS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
#	@mkdir -p $(OBJS_DIR)/operations
	$(CC) $(CFLAGS) -MMD -c $< -o $@

clean:
	make clean -C libft
	rm -rf $(OBJS_DIR)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
