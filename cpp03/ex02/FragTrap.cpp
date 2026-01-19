/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:26:54 by romukena          #+#    #+#             */
/*   Updated: 2026/01/19 16:10:24 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap with no name is created" << std::endl;
}

FragTrap::FragTrap(const std::string _Nname) : ClapTrap(_Nname) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " is created" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->_name << " is destroyed" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	ClapTrap::operator=(other);
	std::cout << "Copy FragTrap " << other._name << " is assigned" << std::endl;
	return *this;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << "Copy FragTrap " << other._name << " is created" << std::endl;
}

void FragTrap::attack(const std::string &target) {
	if (this->_energyPoints >= 1 && this->_hitPoints >= 1) {
		std::cout << "FragTrap " << this->_name << " attacks " << target
				  << ", causing " << this->_attackDamage << " points of damage!"
				  << std::endl;
		this->_energyPoints--;
		return;
	}
	if (this->_energyPoints < 1) {
		std::cerr
			<< this->_name
			<< ", there is no energy points on this character, You can't attack"
			<< std::endl;
	}
	if (this->_hitPoints < 1) {
		std::cerr << this->_name
				  << ", there is no HP on this character, You can't attack"
				  << std::endl;
	}
}

void FragTrap::highFivesGuys(void) {
	if (_name.empty()) {
		std::cout << "FragTrap with no name want high fives" << std::endl;
		return;
	}
	std::cout << "FragTrap " << _name << " want high fives" << std::endl;
}