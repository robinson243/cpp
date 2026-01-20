/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:09:06 by romukena          #+#    #+#             */
/*   Updated: 2026/01/21 00:03:48 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat";
	std::cout << "Cat is create" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat is dead" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Copy Cat is create" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	Animal::operator=(other);
	std::cout << "Copy Cat is assigned" << std::endl;
	return *this;
}

std::string Cat::getType() const
{
	return this->_type;
}

void Cat::makeSound() const
{
	std::cout << "MEOOOW !" << std::endl;
}