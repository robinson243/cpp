/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:17:03 by romukena          #+#    #+#             */
/*   Updated: 2026/01/20 23:50:35 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dog.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog";
	std::cout << "Dog is create" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog is dead" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Copy Dog is create" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	Animal::operator=(other);
	std::cout << "Copy Dog is assigned" << std::endl;
	return *this;
}

std::string Dog::getType() const
{
	return this->_type;
}

void Dog::makeSound() const
{
	std::cout << "WAAAAF !" << std::endl;
}