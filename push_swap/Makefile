# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 17:41:21 by jihyeole          #+#    #+#              #
#    Updated: 2023/04/06 01:36:21 by jihyeole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap 
SRC_DIR = ./src/
SRC_NAME = main.c init.c push_args_to_a.c rules.c move_head_tail.c \
	   utils.c push_a_to_b.c check.c quicksort.c stack_utils.c \
	   small_stack.c push_b_to_a_1.c push_b_to_a_2.c
SRCS = $(addprefix $(SRC_DIR),$(SRC_NAME))
OBJS = $(SRCS:.c=.o)
CC = cc 
CFLAGS = -Wall -Wextra -Werror
LIBS = -Llibft -lft
BNAME = checker
BSRC_DIR = ./bonus/
BSRC_NAME = main_bonus.c rules_bonus.c init_bonus.c utils_bonus.c \
			put_num_to_a_bonus.c check_bonus.c move_head_tail_bonus.c
BSRCS = $(addprefix $(BSRC_DIR),$(BSRC_NAME))
BOBJS = $(BSRCS:.c=.o)

all : $(NAME)

bonus : $(BNAME)

$(NAME) : $(OBJS)
	make -C libft
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

%.o : $(SRC_DIR)%.c 
	$(CC) $(CFLAGS) -c $<
	
%.o : $(BSRC_DIR)%.c 
	$(CC) $(CFLAGS) -c $<

clean : 
	make -C libft clean 
	rm -f $(OBJS) $(BOBJS)

fclean : clean
	rm -f $(NAME) $(BNAME)
	make -C libft fclean

re : fclean all 

$(BNAME) : $(BOBJS)
	make -C libft
	$(CC) $(BOBJS) $(LIBS) -o $(BNAME)

.PHONY : all clean fclean re bonus