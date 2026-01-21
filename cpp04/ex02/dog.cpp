/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:17:03 by romukena          #+#    #+#             */
/*   Updated: 2026/01/21 16:05:10 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dog.hpp"

Dog::Dog() : AAnimal()
{
	_type = "Dog";
	_attribute = new Brain();
	std::cout << "Dog is create" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog is dead" << std::endl;
	delete _attribute;
}

Dog::Dog(const Dog &other) : AAnimal(other)
{
	this->_attribute = new Brain(*other._attribute);
	std::cout << "Copy Dog is create" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
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