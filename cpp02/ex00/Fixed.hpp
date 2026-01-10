/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:06:09 by romukena          #+#    #+#             */
/*   Updated: 2026/01/08 17:58:48 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int _integer;
	const static int _numberBits;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& object);
	Fixed &operator=(const Fixed& object);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};



#endif