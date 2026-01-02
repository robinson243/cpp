/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 01:56:21 by romukena          #+#    #+#             */
/*   Updated: 2026/01/01 23:51:49 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// HumanA::HumanA() {}
HumanA::~HumanA() {}

void HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon_type.getType() << std::endl;
}


HumanA::HumanA(std::string newName, Weapon newWeapon)
{
	weapon_type = newWeapon;
	name = newName;
}