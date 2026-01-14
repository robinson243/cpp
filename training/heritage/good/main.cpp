#include "unit.hpp"
#include "character.hpp"
#include "quest.hpp"

int main()
{
	Unit npc {114, "Forgeron Gibbons"};
	// std::cout << npc.getName() << std::endl;
	// std::cout << npc.getId() << std::endl;

	Character c{25, "John Doe", 2};
	// std::cout << c.getName() << std::endl;
	// std::cout << c.getId() << std::endl;
	// std::cout << c.getLevel() << std::endl;
	Quest("Tourte au sanglier", "Rapporte 5 morceaux de viandes");
	return 0;
}