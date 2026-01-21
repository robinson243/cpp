/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:48:57 by romukena          #+#    #+#             */
/*   Updated: 2026/01/21 17:57:51 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
}
AMateria::~AMateria() {
}

AMateria &AMateria::operator=(const AMateria &other) {
	if (this != &other)
		this->_type = other._type;
	return *this;
}
AMateria::AMateria(const AMateria &other) {
	if (this != &other)
		this->_type = other._type;
}

std::string AMateria::&getType() const {
}