/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:14:21 by romukena          #+#    #+#             */
/*   Updated: 2026/01/22 20:56:03 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character()
{
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
	}
}
Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
			delete this->_inventory[i];
	}
}

Character::Character(const Character &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
			delete this->_inventory[i];
		for (int i = 0; i < 4; i++)
		{
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return *this;
}

Character::Character(const std::string &_otherName) : _name(_otherName)
{
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
	}
}

std::string const &Character::getName() const
{
	return _name;
}

void Character::equip(AMateria *m)
{
	if (m == NULL)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 4 && idx >= 0)
	{
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx <= 4)
	{
		if (this->_inventory[idx] != NULL)
			this->_inventory[idx]->use(target);
	}

	return;
}