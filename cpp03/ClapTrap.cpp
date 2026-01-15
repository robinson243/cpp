/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 00:20:47 by romukena          #+#    #+#             */
/*   Updated: 2026/01/15 01:26:26 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string _Nname)
{
	_name = _Nname;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap() {}
ClapTrap::~ClapTrap() {}

void ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints >= 1 && this->_hitPoints >= 1)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
		return;
	}
	if (this->_energyPoints < 1)
	{
		std::cerr << this->_name << ", there is no energy points on this character, You can't attack" << std::endl;
	}
	if (this->_hitPoints < 1)
	{
		std::cerr << this->_name << ", there is no HP on this character, You can't attack" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints >= 1)
	{
		std::cout << "ClapTrap " << this->_name << " is attacked " << " you lost " << amount << " hit points" << std::endl;
		if (amount >= this->_hitPoints)
		{
			std::cout << this->_name << " is dead" << std::endl;
			this->_hitPoints = 0;
		}
		if (amount < this->_hitPoints)
			this->_hitPoints -= amount;
		return;
	}
	std::cout << this->_name << " is already dead. You don't need to attack him again" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints >= 1 && this->_hitPoints >= 1)
	{
		this->_energyPoints--;
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name << " is healed" << " now he gain " << amount << " of hit points!" << std::endl;
		return;
	}
	if (this->_energyPoints < 1)
	{
		std::cout << this->_name << ", You can't gave him HP, i don't have enough energy points" << std::endl;
	}
	if (this->_hitPoints < 1)
	{
		std::cout << this->_name << ", You can't gave him HP, i'm dead" << std::endl;
	}
}