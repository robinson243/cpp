/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:59:46 by romukena          #+#    #+#             */
/*   Updated: 2026/01/18 16:05:10 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	std::cout << "ScavTrap " << this->_name << " is destroyed" << std::endl;
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

void ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints >= 1 && this->_hitPoints >= 1)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target
				  << ", causing " << this->_attackDamage << " points of damage!"
				  << std::endl;
		this->_energyPoints--;
		return;
	}
	if (this->_energyPoints < 1)
	{
		std::cerr
			<< this->_name
			<< ", there is no energy points on this character, You can't attack"
			<< std::endl;
	}
	if (this->_hitPoints < 1)
	{
		std::cerr << this->_name
				  << ", there is no HP on this character, You can't attack"
				  << std::endl;
	}
}

void ScavTrap::guardGate()
{
	if (_name.empty())
	{
		std::cout << "U don't have name but u are in mode GateKeeper" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}