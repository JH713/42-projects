# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 14:02:55 by jihyeole          #+#    #+#              #
#    Updated: 2023/03/16 19:19:36 by jihyeole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = main.c \
       free.c \
	   img.c \
	   map.c \
	   so_long_utils.c \
	   window.c
OBJS = $(SRCS:.c=.o)
CC = cc 
CFLAGS = -Wall -Werror -Wextra
LIBS = -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit 

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft
	make -C mlx
	$(CC) $(OBJS) $(LIBS) -o $(NAME) 

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean: 
	make -C libft clean 
	make -C mlx clean 
	rm -f $(OBJS)
	
fclean : clean
	rm -f $(NAME)
	make -C libft fclean 

re : fclean all

.PHONY: all clean fclean re