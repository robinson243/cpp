/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 00:20:47 by romukena          #+#    #+#             */
/*   Updated: 2026/01/19 16:07:40 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string _Nname)
{
	_name = _Nname;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "ClapTrap " << _name << " is created" << std::endl;
}

ClapTrap::ClapTrap()
{
	_name = "";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "ClapTrap with no name is created" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " is destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: _name(other._name), _hitPoints(other._hitPoints),
	  _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "Copy ClapTrap " << other._name << " is created" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_attackDamage = other._attackDamage;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		std::cout << "Copy ClapTrap " << other._name << " is assigned" << std::endl;
	}
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints >= 1 && this->_hitPoints >= 1)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target
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

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints >= 1)
	{
		std::cout << "ClapTrap " << this->_name << " is attacked "
				  << " you lost " << amount << " hit points" << std::endl;
		if (amount >= this->_hitPoints)
		{
			std::cout << this->_name << " is dead" << std::endl;
			this->_hitPoints = 0;
		}
		if (amount < this->_hitPoints)
			this->_hitPoints -= amount;
		return;
	}
	std::cout << this->_name
			  << " is already dead. You don't need to attack him again"
			  << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints >= 1 && this->_hitPoints >= 1)
	{
		this->_energyPoints--;
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name << " is healed"
				  << " now he gain " << amount << " of hit points!"
				  << std::endl;
		return;
	}
	if (this->_energyPoints < 1)
	{
		std::cout
			<< this->_name
			<< ", You can't gave him HP, i don't have enough energy points"
			<< std::endl;
	}
	if (this->_hitPoints < 1)
	{
		std::cout << this->_name << ", You can't gave him HP, i'm dead"
				  << std::endl;
	}
}