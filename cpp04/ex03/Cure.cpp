/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:43:39 by romukena          #+#    #+#             */
/*   Updated: 2026/01/22 20:24:04 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() {
	_type = "cure";
}

Cure::~Cure() {
}

Cure::Cure(const Cure &other) : AMateria(other) {
}

Cure &Cure::operator=(const Cure &other) {
	AMateria::operator=(other);
	return *this;
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

Cure *Cure::clone() const {
	Cure *copy = new Cure;
	return copy;
}
