# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 22:09:17 by jihyeole          #+#    #+#              #
#    Updated: 2023/04/14 08:58:22 by jihyeole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SRC_DIR = ./src/
SRC_NAME = main.c path.c pipex_utils.c
SRCS = $(addprefix $(SRC_DIR),$(SRC_NAME))
OBJS = $(SRCS:.c=.o)
CC = cc 
CFLAGS = -Wall -Wextra -Werror
LIBS = -Llibft -lft
BSRC_DIR = ./bonus/
BSRC_NAME = main_bonus.c path_bonus.c parent_bonus.c child_bonus.c pipex_utils_bonus.c
BSRCS = $(addprefix $(BSRC_DIR),$(BSRC_NAME))
BOBJS = $(BSRCS:.c=.o)

ifdef BONUS
	OBJ_FILES = $(BOBJS)
else
	OBJ_FILES = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	make -C libft
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

%.o : $(SRC_DIR)%.c 
	$(CC) $(CFLAGS) -c $<
	
%.o : $(BSRC_DIR)%.c 
	$(CC) $(CFLAGS) -c $<

bonus :
	make BONUS=1 all

clean : 
	make -C libft clean 
	rm -f $(OBJS) $(BOBJS)

fclean : clean
	rm -f $(NAME)
	make -C libft fclean

re : fclean all 

.PHONY : all clean fclean re bonus