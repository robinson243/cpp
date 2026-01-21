CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = AAnimal

SRC = animal.cpp  cat.cpp  dog.cpp  main.cpp brain.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re