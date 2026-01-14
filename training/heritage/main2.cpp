#include "perso.hpp"

int main(void)
{
	Personnage player1("John Doe",100, 15, 1, 0, 0);
	std::cout << player1.getName()<< std::endl;
}