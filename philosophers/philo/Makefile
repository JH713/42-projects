# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 16:33:39 by jihyeole          #+#    #+#              #
#    Updated: 2023/05/01 21:01:18 by jihyeole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS = main.c philo_utils1.c philo_utils2.c print_error.c fork.c \
		   mutex.c thread.c print_msg.c init_args_info.c monitoring.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror 

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all 

.PHONY : all clean fclean re