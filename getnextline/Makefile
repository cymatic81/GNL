# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchapman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 13:21:37 by jchapman          #+#    #+#              #
#    Updated: 2023/03/03 17:48:11 by jchapman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getnextline.a

CC = gcc

CFLAGS = -Werror -Wextra -Wall -g
 
SRCS =	get_next_line.c \
		get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

BONUS =	get_next_line_bonus.c \
		get_next_line_utils_bonus.c \

OBJS_B = $(BONUS:.c=.o)

%.o: %.c
	${CC} -c $(CFLAGS) $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

bonus: $(OBJS_B)
	ar -rcs $(NAME) $(OBJS_B)

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean:	clean
		rm -f $(NAME)

re: fclean all
