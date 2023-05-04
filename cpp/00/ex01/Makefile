NAME = phonebook
SRCS = Contact.cpp PhoneBook.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDES = Contact.hpp PhoneBook.hpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJS) 
	$(CC) $(OBJS) -o $(NAME)

%.o : %.cpp $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all 

.PHONY : all clean fclean re