/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:17:03 by romukena          #+#    #+#             */
/*   Updated: 2026/01/21 16:08:49 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dog.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog";
	_attribute = new Brain();
	std::cout << "Dog is create" << std::endl;
}

Dog::~Dog()
{
	delete _attribute;
	std::cout << "Dog is dead" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	this->_attribute = new Brain(*other._attribute);
	std::cout << "Copy Dog is create" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->_attribute;
		this->_attribute = new Brain(*other._attribute);
		std::cout << "Copy Dog is assigned" << std::endl;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "WAAAAF !" << std::endl;
}