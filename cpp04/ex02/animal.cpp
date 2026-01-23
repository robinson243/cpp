/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:04:55 by romukena          #+#    #+#             */
/*   Updated: 2026/01/23 11:04:19 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"

AAnimal::AAnimal()
{
	_type = "Animal";
	std::cout << "Animal is create" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "Animal is dead" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : _type(other._type)
{
	std::cout << "Copy Animal is create" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
	{
		this->_type = other._type;
		std::cout << "Copy Animal is assigned" << std::endl;
	}
	return *this;
}

std::string AAnimal::getType() const
{
	return this->_type;
}
