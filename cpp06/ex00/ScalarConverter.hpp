/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:55:32 by romukena          #+#    #+#             */
/*   Updated: 2026/03/13 01:00:28 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <stdint.h>
#include <string>
#include <cctype>

class ScalarConverter {
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

	void intToChar();
	void doubleToChar();
	void floatToChar();
	int doubleToInt();
	int floatToInt();
	int strToInt();
	float intToFloat();
	float doubleToFloat();
	float strToFloat();
	double intToDouble();
	double floatToDouble();
	double strToDouble();

	void convert();
};

#endif