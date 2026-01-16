/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:06:09 by romukena          #+#    #+#             */
/*   Updated: 2026/01/16 17:19:17 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <cmath>


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
	int toInt(void) const;
	float toFloat(void) const;
	Fixed(const int num);
	Fixed(const float num);
	friend std::ostream& operator<<(std::ostream &os, const Fixed& object);
};

int power(int base, int exponent);

#endif