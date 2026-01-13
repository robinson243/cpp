#include "HumanB.hpp"

HumanB::HumanB(std::string _Name)
{
	this->_name = _Name;
}

void HumanB::setWeapon(Weapon _nWeapon)
{
	*this->_weapon = _nWeapon;
}

void HumanB::attack()
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}