CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

NAME = MastaDinguerie

SRC = AMateria.cpp  Character.cpp  Cure.cpp  Ice.cpp main.cpp  MateriaSource.cpp
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