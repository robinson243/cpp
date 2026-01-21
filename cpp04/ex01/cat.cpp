/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:09:06 by romukena          #+#    #+#             */
/*   Updated: 2026/01/21 16:09:00 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat";
	_attribute = new Brain();
	std::cout << "Cat is create" << std::endl;
}

Cat::~Cat()
{
	delete _attribute;
	std::cout << "Cat is dead" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	this->_attribute = new Brain(*other._attribute);
	std::cout << "Copy Cat is create" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->_attribute;
		this->_attribute = new Brain(*other._attribute);
		std::cout << "Copy Cat is assigned" << std::endl;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "MEOOOW !" << std::endl;
}