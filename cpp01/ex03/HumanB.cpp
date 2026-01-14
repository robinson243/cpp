/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:04:22 by romukena          #+#    #+#             */
/*   Updated: 2026/01/14 16:04:36 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string _Name) : _name(_Name), _weapon(NULL) {
}

void HumanB::setWeapon(Weapon &_nWeapon) {
	this->_weapon = &_nWeapon;
}

void HumanB::attack() {
	if (this->_weapon)
		std::cout << this->_name << " attacks with their "
				  << this->_weapon->getType() << std::endl;
}