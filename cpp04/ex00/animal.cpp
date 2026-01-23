/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:04:55 by romukena          #+#    #+#             */
/*   Updated: 2026/01/23 11:03:06 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"

Animal::Animal()
{
	_type = "Animal";
	std::cout << "Animal is create" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal is dead" << std::endl;
}

Animal::Animal(const Animal &other) :_type(other._type)
{
	std::cout << "Copy Animal is create" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		this->_type = other._type;
		std::cout << "Copy Animal is assigned" << std::endl;
	}
	return *this;
}

std::string Animal::getType() const
{
	return this->_type;
}

void Animal::makeSound() const
{
	std::cout << "HEY HO !" << std::endl;
}