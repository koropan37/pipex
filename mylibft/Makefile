# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 10:34:56 by skimura           #+#    #+#              #
#    Updated: 2025/07/23 22:33:12 by skimura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a

SRCS    = \
	libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c \
	libft/ft_isprint.c libft/ft_strlen.c libft/ft_memset.c libft/ft_bzero.c \
	libft/ft_memcpy.c libft/ft_memmove.c libft/ft_strlcpy.c libft/ft_strlcat.c \
	libft/ft_toupper.c libft/ft_tolower.c libft/ft_strchr.c libft/ft_strrchr.c \
	libft/ft_strncmp.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_strnstr.c \
	libft/ft_atoi.c libft/ft_calloc.c libft/ft_strdup.c libft/ft_substr.c \
	libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c libft/ft_itoa.c \
	libft/ft_strmapi.c libft/ft_striteri.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c \
	libft/ft_putendl_fd.c libft/ft_putnbr_fd.c \
	libft/ft_lstnew.c libft/ft_lstadd_front.c libft/ft_lstsize.c libft/ft_lstlast.c \
	libft/ft_lstadd_back.c libft/ft_lstdelone.c libft/ft_lstclear.c libft/ft_lstiter.c \
	libft/ft_lstmap.c \
	printf/ft_printf.c printf/ft_printf_str.c printf/ft_printf_number.c \
	dprintf/ft_dprintf.c dprintf/ft_dprintf_str.c dprintf/ft_dprintf_nbr.c \
	gnl/get_next_line.c gnl/get_next_line_utils.c\
	addition/ft_strcmp.c addition/ft_strcspn.c addition/ft_strcpy.c\
	addition/ft_strspn.c addition/ft_strpbrk.c addition/ft_strrev.c addition/ft_max.c\
	addition/ft_min.c addition/ft_swap_bits.c addition/ft_reverse_bits.c\
	addition/ft_print_bits.c addition/ft_gcd.c addition/ft_lcm.c addition/ft_prime.c\
	addition/ft_abs.c addition/ft_strndup.c addition/ft_realloc.c addition/ft_strcat.c


OBJS    = $(SRCS:.c=.o)

CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM			= rm -f
AR          = ar
ARFLAGS     = rcs
INCLUDES = -I include
MAKEFLAGS += --no-print-directory


BLACK   = \033[0;30m
RED     = \033[0;31m
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
BLUE    = \033[0;34m
MAGENTA = \033[0;35m
CYAN    = \033[0;36m
WHITE   = \033[0;37m
RESET   = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)[INFO]$(CYAN) Building $(WHITE)$(NAME)...$(RESET)"
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "$(GREEN)[OK]$(BLUE) Build completed!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "$(RED)[DONE] Object files removed.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(YELLOW)[DELETE]$(RED) All clean: $(NAME)$(RESET)"

re: fclean all

.PHONY: all clean fclean re
