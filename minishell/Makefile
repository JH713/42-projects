# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 21:56:35 by jihyeole          #+#    #+#              #
#    Updated: 2023/05/11 18:21:30 by jihyeole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRCS = main.c error.c
OBJS = $(SRCS:.c=.o)
CC = CC
CFLAGS = -Wall -Wextra -Werror 
LIBS = -Llibft -lft

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft bonus
	$(CC) $(OBJS) $(LIBS) -o $(NAME) -lreadline

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	make -C libft clean
	rm -f $(OBJS)

fclean : clean
	make -C libft fclean
	rm -f $(NAME)

re : fclean all 

.PHONY : all clean fclean re