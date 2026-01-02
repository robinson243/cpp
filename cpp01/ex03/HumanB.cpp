/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 01:56:21 by romukena          #+#    #+#             */
/*   Updated: 2026/01/01 20:55:11 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB() {}
HumanB::~HumanB() {}

void HumanB::attack(void)
{
	std::cout << name << " attacks with their " << weapon_type.getType() << std::endl;
}

void HumanB::setWeapon(Weapon weapon)
{
	weapon_type = weapon;
}
HumanB::HumanB(std::string _name)
{
	name = _name;
}