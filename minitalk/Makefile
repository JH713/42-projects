# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 07:27:57 by jihyeole          #+#    #+#              #
#    Updated: 2023/05/06 20:35:30 by jihyeole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CNAME = client
CSRCS = client.c
COBJS = $(CSRCS:.c=.o)

SNAME = server
SSRCS = server.c
SOBJS = $(SSRCS:.c=.o)

CC = cc 
CFLAGS = -Wall -Wextra -Werror
LIBS = -Llibft -lft

all : $(CNAME) $(SNAME)

$(CNAME) : $(COBJS)
	make -C libft
	$(CC) $(COBJS) $(LIBS) -o $(CNAME)
	
$(SNAME) : $(SOBJS)
	make -C libft
	$(CC) $(SOBJS) $(LIBS) -o $(SNAME)

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	make -C libft clean 
	rm -f $(COBJS) $(SOBJS)

fclean : clean
	make -C libft fclean 
	rm -f $(CNAME) $(SNAME)

re : fclean all 

.PHONY : all clean fclean re