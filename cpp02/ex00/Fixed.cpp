/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:08:36 by romukena          #+#    #+#             */
/*   Updated: 2026/01/16 12:33:43 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	_integer = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &object){
	std::cout << "Copy constructor called" << std::endl;
	_integer = object.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &object) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &object) {
		this->_integer = object.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _integer;
}

void Fixed::setRawBits(int const raw) {
	_integer = raw;
}
