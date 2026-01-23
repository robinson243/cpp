/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongcat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 12:57:05 by romukena          #+#    #+#             */
/*   Updated: 2026/01/23 12:58:19 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrongcat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "WrongCat is create" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat is dead" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "Copy WrongCat is create" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	WrongAnimal::operator=(other);
	std::cout << "Copy WrongCat is assigned" << std::endl;
	return *this;
}

std::string WrongCat::getType() const
{
	return this->_type;
}

void WrongCat::makeSound() const
{
	std::cout << "HIHIHIHI!" << std::endl;
}