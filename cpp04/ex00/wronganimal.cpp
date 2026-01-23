/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wronganimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 12:54:11 by romukena          #+#    #+#             */
/*   Updated: 2026/01/23 12:55:28 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wronganimal.hpp"


WrongAnimal::WrongAnimal()
{
	_type = "WrongAnimal";
	std::cout << "WrongAnimal is create" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal is dead" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) :_type(other._type)
{
	std::cout << "Copy WrongAnimal is create" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		this->_type = other._type;
		std::cout << "Copy WrongAnimal is assigned" << std::endl;
	}
	return *this;
}

std::string WrongAnimal::getType() const
{
	return this->_type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "KOF KOF !" << std::endl;
}