/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:04:51 by romukena          #+#    #+#             */
/*   Updated: 2026/01/14 16:04:52 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {};
Weapon::~Weapon() {};

Weapon::Weapon(std::string _nType) : _type(_nType) {}

const std::string& Weapon::getType()
{
	return (_type);
}

void Weapon::setType(std::string _nType)
{
	this->_type = _nType;
}
