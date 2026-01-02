/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 00:17:44 by romukena          #+#    #+#             */
/*   Updated: 2026/01/01 21:41:49 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}
Weapon::~Weapon() {}

const std::string& Weapon::getType()
{
	const std::string &ref = type;
	return ref;
}

void Weapon::setType(std::string newtype)
{
	type = newtype;
	// std::cout << "test" << std::endl;
}

Weapon::Weapon(std::string _type)
{
	type = _type;
}