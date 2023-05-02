# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 16:33:39 by jihyeole          #+#    #+#              #
#    Updated: 2023/05/01 21:01:22 by jihyeole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
SRCS = main_bonus.c philo_utils1_bonus.c philo_utils2_bonus.c \
		   print_error_bonus.c semaphore_bonus.c philo_process_bonus.c \
		   init_args_info_bonus.c
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