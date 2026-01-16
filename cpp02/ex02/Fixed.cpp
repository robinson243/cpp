/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:08:36 by romukena          #+#    #+#             */
/*   Updated: 2026/01/16 13:17:16 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_numberBits = 8;

Fixed::Fixed()
{
	_integer = 0;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &object) : _integer(object.getRawBits())
{
}

Fixed &Fixed::operator=(const Fixed &object)
{
	if (this != &object)
	{
		this->_integer = object.getRawBits();
	}
	return *this;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return this->toFloat() * other.toFloat();
}

Fixed& Fixed::operator++()
{
	_integer += 1;
	return *this; 
}

Fixed Fixed::operator++(int)
{
	Fixed copy = *this;
	(*this)._integer += 1;
	return copy;
}

float Fixed::max(const Fixed& a, const Fixed& b)
{
	return a.toFloat() > b.toFloat() ? a.toFloat() : b.toFloat();
}

int Fixed::getRawBits(void) const
{
	return _integer;
}

void Fixed::setRawBits(int const raw)
{
	_integer = raw;
}

Fixed::Fixed(const int num) : _integer(num << _numberBits)
{
}

Fixed::Fixed(const float num)
{
	_integer = roundf(num * (1 << _numberBits));
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