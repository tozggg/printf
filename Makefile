# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 13:17:17 by taejkim           #+#    #+#              #
#    Updated: 2021/06/09 10:03:20 by taejkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar -rcs
RM = rm -f

SRCS = ft_printf.c set_info.c \
		print_num.c print_text.c print_utils.c\
		itoa.c utils1.c utils2.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
		$(AR) $@ $^

all: $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
