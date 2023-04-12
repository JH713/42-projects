# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 22:09:17 by jihyeole          #+#    #+#              #
#    Updated: 2023/04/11 21:58:01 by jihyeole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SRCS = main.c path.c
OBJS = $(SRCS:.c=.o)
CC = cc 
CFLAGS = -Wall -Wextra -Werror
LIBS = -Llibft -lft

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

%.o : %.c 
	$(CC) $(CFLAGS) -c $<

clean : 
	make -C libft clean 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)
	make -C libft fclean

re : fclean all 

.PHONY : all clean fclean re 