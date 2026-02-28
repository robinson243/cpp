CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

NAME = BiroBiro

SRC = Aform.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp Bureaucrat.cpp main.cpp \
PresidentialPardonForm.cpp
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
	rm -f *_shrubbery

re: fclean all

.PHONY: all clean fclean re