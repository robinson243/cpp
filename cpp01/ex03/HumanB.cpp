/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 01:56:21 by romukena          #+#    #+#             */
/*   Updated: 2026/01/02 03:35:08 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB() {}
HumanB::~HumanB() {}

void HumanB::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon_type->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon_type = &weapon;
}
HumanB::HumanB(std::string _name) : weapon_type(NULL), name(_name)
{}