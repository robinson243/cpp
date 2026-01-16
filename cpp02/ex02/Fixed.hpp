/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:06:09 by romukena          #+#    #+#             */
/*   Updated: 2026/01/16 17:04:30 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed
{
private:
	int _integer;
	const static int _numberBits;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &object);
	Fixed &operator=(const Fixed &object);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	Fixed(const int num);
	Fixed(const float num);
	Fixed operator*(const Fixed& other) const;
	Fixed operator++(int i);
	Fixed& operator++();
	static float max(const Fixed& a, const Fixed& b);
	friend std::ostream& operator<<(std::ostream &os, const Fixed& object);
};

int power(int base, int exponent);

#endif