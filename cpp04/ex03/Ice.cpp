/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:15:05 by romukena          #+#    #+#             */
/*   Updated: 2026/01/22 20:44:53 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() {
	_type = "ice";
}

Ice::~Ice() {
}

Ice::Ice(const Ice &other) : AMateria(other) {
}

Ice &Ice::operator=(const Ice &other) {
	AMateria::operator=(other);
	return *this;
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"
			  << std::endl;
}

Ice *Ice::clone() const {
	Ice *copy = new Ice;
	return copy;
}
