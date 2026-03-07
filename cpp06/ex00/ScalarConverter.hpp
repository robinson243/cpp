/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:55:32 by romukena          #+#    #+#             */
/*   Updated: 2026/03/07 00:57:06 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATICCONVERTER_HPP
#define STATICCONVERTER_HPP
#include <iostream>
#include <stdint.h>
#include <cstdlib>
#include <limits>


class ScalarConverter
{
private:
	std::string _lit;
public:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &other);
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter(std::string s);
	std::string getString();
	bool isInt();
	bool isFloat();
	bool isDouble();
	void convert();
};


#endif