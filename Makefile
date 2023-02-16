# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 18:29:28 by davgarci          #+#    #+#              #
#    Updated: 2023/02/16 21:45:13 by davgarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = main.c \
		init.c \
		error.c \
		utils.c \
		dinner.c \
		mutex.c \
		times.c \
		threads.c \

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra
CFLAGS = -Wall -Werror -Wextra
TRHEADS =  -lpthread
CC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(FLAGS) $(TRHEADS) $(OBJS) -o philo


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re