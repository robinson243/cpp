/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:08:36 by romukena          #+#    #+#             */
/*   Updated: 2026/01/16 16:58:25 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_numberBits = 8;

int power(int base, int exponent) {
	int result = 1;
	for (int i = 0; i < exponent; i++) {
		result *= base;
	}
	return result;
}

Fixed::Fixed() {
	_integer = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &object) {
	std::cout << "Copy constructor called" << std::endl;
	*this = object;
}

Fixed &Fixed::operator=(const Fixed &object) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &object) {
		this->_integer = object._integer;
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

Fixed::Fixed(const int num) : _integer(num * power(2, _numberBits)) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num) {
	_integer = roundf(num * power(2, _numberBits));
	std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const {
	float floatNumber = _integer / (float)power(2, _numberBits);
	return (floatNumber);
}

int Fixed::toInt(void) const {
	int intNumber = _integer / (int)power(2, _numberBits);
	return intNumber;
}

std::ostream &operator<<(std::ostream &os, const Fixed &object) {
	os << object.toFloat();
	return os;
}