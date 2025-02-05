# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 13:41:01 by lgirerd           #+#    #+#              #
#    Updated: 2025/02/05 15:29:20 by lgirerd          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

############################# SOURCES #############################

CONV_DIR = conversion/
CONV_SRCS = ft_atoi.c \
			ft_itoa.c \
			ft_tolower.c \
			ft_toupper.c

FD_DIR = file_desc/
FD_SRCS =   ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c

IS_DIR = is/
IS_SRCS =   ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c

LINKLIST_DIR = linked_lists/
LINKLIST_SRCS = ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstlast.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lstsize.c

MEMORY_DIR = memory/
MEMORY_SRCS =   ft_bzero.c \
				ft_calloc.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c

STRING_DIR = string/
STRING_SRCS = 	ft_split.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c

PRINTF_DIR = printf/
PRINTF_SRCS = 	ft_printf.c \
				ft_subprints.c \
				ft_printfutils.c \
				ft_printfutils2.c \
				ft_printhex.c \
				ft_printptr.c 

GNL_DIR = gnl/
GNL_SRCS = 		get_next_line.c \
				get_next_line_utils.c

############################# DIRECTORIES ##############################

SRCS_DIR = srcs/
SRCS =	$(addprefix $(SRCS_DIR)$(CONV_DIR), $(CONV_SRCS)) \
		$(addprefix $(SRCS_DIR)$(FD_DIR), $(FD_SRCS)) \
		$(addprefix $(SRCS_DIR)$(IS_DIR), $(IS_SRCS)) \
		$(addprefix $(SRCS_DIR)$(LINKLIST_DIR), $(LINKLIST_SRCS)) \
		$(addprefix $(SRCS_DIR)$(MEMORY_DIR), $(MEMORY_SRCS)) \
		$(addprefix $(SRCS_DIR)$(STRING_DIR), $(STRING_SRCS)) \
		$(addprefix $(SRCS_DIR)$(PRINTF_DIR), $(PRINTF_SRCS)) \
		$(addprefix $(SRCS_DIR)$(GNL_DIR), $(GNL_SRCS))

OBJS_DIR = .objs/

OBJS = $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)
DEPS := $(OBJS:.o=.d)

############################# RULES ##############################

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)$(CONV_DIR)
	@mkdir -p $(OBJS_DIR)$(FD_DIR)
	@mkdir -p $(OBJS_DIR)$(IS_DIR)
	@mkdir -p $(OBJS_DIR)$(LINKLIST_DIR)
	@mkdir -p $(OBJS_DIR)$(MEMORY_DIR)
	@mkdir -p $(OBJS_DIR)$(STRING_DIR)
	@mkdir -p $(OBJS_DIR)$(PRINTF_DIR)
	@mkdir -p $(OBJS_DIR)$(GNL_DIR)
	@echo "Compiling $<"; $(CC) $(CFLAGS) -MMD -c $< -o $@

clean :
	rm -rf $(OBJS_DIR)

fclean :    clean
	rm -f $(NAME)

re : fclean all

-include $(DEPS)

.PHONY :  all clean fclean re
