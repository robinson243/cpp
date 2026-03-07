/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:55:30 by romukena          #+#    #+#             */
/*   Updated: 2026/03/07 01:43:33 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : _lit("none")
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)
	{
		;
	}
	return *this;
}

ScalarConverter::ScalarConverter(std::string s)
{
	int i = 0;
	int j = 0;
	while (s[i])
	{
		while (isspace(s[i]))
			s[i++];
		if (!isspace(s[i]))
			j = i;
		while (s[i])
			s[i++];
	}
	this->_lit = s.substr(j, i - j);
}

std::string ScalarConverter::getString()
{
	return this->_lit;
}

bool ScalarConverter::isInt()
{
	int i = 0;
	while (this->_lit[i] >= '0' && this->_lit[i] <= '9')
	{
		i++;
	}
	if (!this->_lit[i] == '\0')
		return false;
	long long numb = strtoll(this->_lit.c_str(), NULL, 10);
	if (numb < -2147483648 || numb > 2147483647)
		return false;

	return true;
}

bool ScalarConverter::isDouble()
{
	int i = 0;
	int isPoint = 0;
	if (this->_lit[0] == '.')
		return false;
	while ((this->_lit[i] >= '0' && this->_lit[i] <= '9') || this->_lit[i] == '.')
	{
		if (this->_lit[i] == '.')
			isPoint++;
		i++;
	}
	if (!this->_lit[i] == '\0' || isPoint > 1 || isPoint == 0)
		return false;
	long double numb = strtod(this->_lit.c_str(), NULL);
	if (numb < std::numeric_limits<double>::min() || numb > std::numeric_limits<double>::max())
		return false;
	if (this->_lit[i - 1] == '.')
		return false;
	return true;
}

bool ScalarConverter::isFloat()
{
	int i = 0;
	int isPoint = 0;
	int isF = 0;
	if (this->_lit[0] == '.')
		return false;
	while ((this->_lit[i] >= '0' && this->_lit[i] <= '9') || this->_lit[i] == '.' || this->_lit[i] == 'f')
	{
		if (this->_lit[i] == '.')
			isPoint++;
		if (this->_lit[i] == 'f')
			isF++;
		i++;
	}
	if (!this->_lit[i] == '\0' || isPoint > 1 || isPoint == 0 || isF > 1 || isF == 0)
		return false;
	long double numb = strtod(this->_lit.c_str(), NULL);
	if (numb < std::numeric_limits<float>::min() || numb > std::numeric_limits<float>::max())
		return false;
	if ((this->_lit[i - 1] == '.') || this->_lit[i - 1] != 'f')
		return false;
	return true;
}