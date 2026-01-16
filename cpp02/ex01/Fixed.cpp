/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:08:36 by romukena          #+#    #+#             */
/*   Updated: 2026/01/16 11:35:33 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_numberBits = 8;

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


Fixed::Fixed(const int num) : _integer(num << _numberBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num)
{
	_integer = roundf(num * (1 << _numberBits));
	std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	float floatNumber = _integer / (float)(1 << _numberBits);
	return (floatNumber);
}

int Fixed::toInt(void) const
{
	int intNumber = _integer / (int)(1 << _numberBits);
	return intNumber;
}

std::ostream &operator<<(std::ostream &os, const Fixed &object)
{
	os << object.toFloat();
	return os;
}