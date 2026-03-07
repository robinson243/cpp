/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:55:30 by romukena          #+#    #+#             */
/*   Updated: 2026/03/07 16:29:49 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : _lit("none") {
}

ScalarConverter::~ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	(void)other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	if (this != &other) {
		;
	}
	return *this;
}

ScalarConverter::ScalarConverter(std::string s) {
	int i = 0;
	int j = 0;
	while (s[i]) {
		while (isspace(s[i]))
			s[i++];
		if (!isspace(s[i]))
			j = i;
		while (s[i])
			s[i++];
	}
	this->_lit = s.substr(j, i - j);
}

std::string ScalarConverter::getString() {
	return this->_lit;
}

bool ScalarConverter::isInt() {
	int i = 0;
	while (this->_lit[i] >= '0' && this->_lit[i] <= '9') {
		i++;
	}
	if (!this->_lit[i] == '\0')
		return false;
	long long numb = strtoll(this->_lit.c_str(), NULL, 10);
	if (numb < -2147483648 || numb > 2147483647)
		return false;

	return true;
}

bool ScalarConverter::isDouble() {
	int i = 0;
	int isPoint = 0;
	if (this->_lit[0] == '.')
		return false;
	while ((this->_lit[i] >= '0' && this->_lit[i] <= '9')
		   || this->_lit[i] == '.') {
		if (this->_lit[i] == '.')
			isPoint++;
		i++;
	}
	if (!this->_lit[i] == '\0' || isPoint > 1 || isPoint == 0)
		return false;
	long double numb = strtod(this->_lit.c_str(), NULL);
	if (numb < std::numeric_limits<double>::min()
		|| numb > std::numeric_limits<double>::max())
		return false;
	if (this->_lit[i - 1] == '.')
		return false;
	return true;
}

bool ScalarConverter::isFloat() {
	int i = 0;
	int isPoint = 0;
	int isF = 0;
	if (this->_lit[0] == '.')
		return false;
	while ((this->_lit[i] >= '0' && this->_lit[i] <= '9')
		   || this->_lit[i] == '.' || this->_lit[i] == 'f') {
		if (this->_lit[i] == '.')
			isPoint++;
		if (this->_lit[i] == 'f')
			isF++;
		i++;
	}
	if (this->_lit[i] != '\0' || isPoint > 1 || isF > 1 || isF == 0)
		return false;
	long double numb = strtod(this->_lit.c_str(), NULL);
	if (numb < std::numeric_limits<float>::min()
		|| numb > std::numeric_limits<float>::max())
		return false;
	if ((this->_lit[i - 1] == '.') || this->_lit[i - 1] != 'f')
		return false;
	return true;
}

void ScalarConverter::intToChar() {
	int num = this->strToInt();
	if (num > 32 && num <= 126)
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	else if ((num >= 0 && num < 32) || num == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
}

void ScalarConverter::doubleToChar() {
	int num = this->doubleToInt();
	if (num > 32 && num <= 126)
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	else if ((num >= 0 && num < 32) || num == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
}

void ScalarConverter::floatToChar() {
	int num = this->floatToInt();
	if (num > 32 && num <= 126)
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	else if ((num >= 0 && num < 32) || num == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
}

int ScalarConverter::floatToInt() {
	float num_float = atof(this->_lit.c_str());
	int num = static_cast<int>(num_float);
	return num;
}

int ScalarConverter::doubleToInt() {
	double num_double = atof(this->_lit.c_str());
	int num = static_cast<int>(num_double);
	return num;
}

int ScalarConverter::strToInt() {
	int intNum = atoi(this->_lit.c_str());
	return intNum;
}

float ScalarConverter::intToFloat() {
	int intNum = atoi(this->_lit.c_str());
	float num = static_cast<float>(intNum);
	return num;
}

float ScalarConverter::doubleToFloat() {
	double doubleNum = atof(this->_lit.c_str());
	float num = static_cast<float>(doubleNum);
	return num;
}

float ScalarConverter::strToFloat() {
	float floatNum = atof(this->_lit.c_str());
	return floatNum;
}

double ScalarConverter::intToDouble() {
	int intNum = atoi(this->_lit.c_str());
	double num = static_cast<double>(intNum);
	return num;
}

double ScalarConverter::floatToDouble() {
	float floatNum = atof(this->_lit.c_str());
	double num = static_cast<double>(floatNum);
	return num;
}

double ScalarConverter::strToDouble() {
	double doubleNum = atof(this->_lit.c_str());
	return doubleNum;
}

void ScalarConverter::convert() {
	std::cout << std::fixed << std::setprecision(1);

	if (this->_lit.empty()) {
		std::cout << "char: impossible\nint: impossible\nfloat: "
					 "impossible\ndouble: impossible\n";
		return;
	}
	if (this->_lit == "nan") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
	}
	if (this->_lit == "+inf" || this->_lit == "inf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return;
	}
	if (this->_lit == "-inf" || this->_lit == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return;
	}
	if (this->_lit.length() == 1 && !isdigit(this->_lit[0])) {
		char c = this->_lit[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << std::endl;
		return;
	}
	if (this->isInt()) {
		this->intToChar();
		std::cout << "int: " << this->strToInt() << std::endl;
		std::cout << "float: " << this->intToFloat() << "f" << std::endl;
		std::cout << "double: " << this->intToDouble() << std::endl;
	} else if (this->isDouble()) {
		this->doubleToChar();
		std::cout << "int: " << this->doubleToInt() << std::endl;
		std::cout << "float: " << this->doubleToFloat() << "f" << std::endl;
		std::cout << "double: " << this->strToDouble() << std::endl;
	} else if (this->isFloat()) {
		this->floatToChar();
		std::cout << "int: " << this->floatToInt() << std::endl;
		std::cout << "float: " << this->strToFloat() << "f" << std::endl;
		std::cout << "double: " << this->floatToDouble() << std::endl;
	} else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}
