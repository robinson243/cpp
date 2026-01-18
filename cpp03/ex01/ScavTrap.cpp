#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &_Nname) : ClapTrap(_Nname)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "Scavtrap " << _name << " is created" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "Scavtrap with no name is created" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " is detroyed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
	: ClapTrap(other)
{
	std::cout << "Copy Scavtrap " << other._name << " is created" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	ClapTrap::operator=(other);
	std::cout << "Copy Scavtrap " << other._name << " is assigned" << std::endl;
	return *this;
}

void ScavTrap::guardGate()
{
	if (_name.empty())
	{
		std::cout << "U don't have name but u are in mode GateKeeper" << std::endl;
		return;
	}
	std::cout << this->_name << " is in mode GateKeeper" << std::endl;
}