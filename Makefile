# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/11 21:24:00 by skimura           #+#    #+#              #
#    Updated: 2025/08/14 21:50:58 by skimura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
BONUS_NAME	= pipex

SRC			= \
                src/main.c \
                src/init_pipex.c \
                src/path.c \
               	src/do_pipex.c \
				src/child.c \
				src/parent.c \
                src/error.c \
                src/clean_up.c \
				src/free.c \

BONUS_SRC	= \
                bonus/main_bonus.c \
				bonus/parse_bonus.c \
                bonus/init_pipex_bonus.c \
				bonus/init_utils_bonus.c \
                bonus/path_bonus.c \
                bonus/do_pipex_bonus.c  \
				bonus/child_bonus.c \
				bonus/parent_bonus.c \
				bonus/here_doc_bonus.c \
                bonus/clean_up_bonus.c \
				bonus/free_bonus.c \


OBJS		= $(SRC:.c=.o)
BONUS_OBJS	= $(BONUS_SRC:.c=.o)

INC_DIR		= include
LIBFT_DIR	= mylibft
LIBFT_LIB	= $(LIBFT_DIR)/libft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
INCLUDES	= -I$(INC_DIR) -I$(LIBFT_DIR)
MAKEFLAGS	+= --no-print-directory

RESET	= \033[0m
BOLD	= \033[1m
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
CYAN	= \033[0;36m
WHITE	= \033[0;37m

.PHONY: all bonus clean fclean re

all: $(NAME)

bonus:
	@$(MAKE) BONUS=1 $(BONUS_NAME)

ifeq ($(BONUS),1)
$(NAME): $(LIBFT_LIB) $(BONUS_OBJS)
	@echo  "$(BOLD)$(GREEN)[INFO]$(CYAN) Building $(WHITE)pipex_bonus..."
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT_LIB) $(INCLUDES) -o $(NAME)
	@echo "$(GREEN)[OK]$(BLUE) Bonus build completed!$(RESET)"
else
$(NAME): $(LIBFT_LIB) $(OBJS)
	@echo  "$(BOLD)$(GREEN)[INFO]$(CYAN) Building $(WHITE)$(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(INCLUDES) -o $(NAME)
	@echo "$(GREEN)[OK]$(BLUE) Build completed!$(RESET)"
endif

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)



%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo  "$(BOLD)$(YELLOW)[INFO]$(MAGENTA) Cleaning $(NAME)..."
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@echo "$(RED)[DONE]$(RESET)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME) $(BONUS_NAME)
	@echo "$(BOLD)$(YELLOW)[DELETE]$(RED)All clean $(NAME) $(RESET)"

re: fclean all
