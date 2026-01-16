/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:08:36 by romukena          #+#    #+#             */
/*   Updated: 2026/01/16 17:09:18 by romukena         ###   ########.fr       */
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
}

Fixed::~Fixed() {
}

Fixed::Fixed(const Fixed &object) : _integer(object.getRawBits()) {
}

Fixed &Fixed::operator=(const Fixed &object) {
	if (this != &object) {
		this->_integer = object.getRawBits();
	}
	return *this;
}

Fixed Fixed::operator*(const Fixed &other) const {
	return this->toFloat() * other.toFloat();
}

Fixed &Fixed::operator++() {
	_integer += 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed copy = *this;
	(*this)._integer += 1;
	return copy;
}

float Fixed::max(const Fixed &a, const Fixed &b) {
	return a.toFloat() > b.toFloat() ? a.toFloat() : b.toFloat();
}

int Fixed::getRawBits(void) const {
	return _integer;
}

void Fixed::setRawBits(int const raw) {
	_integer = raw;
}

Fixed::Fixed(const int num) : _integer(num * power(2, _numberBits)) {
}

Fixed::Fixed(const float num) {
	_integer = roundf(num * (power(2, _numberBits)));
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