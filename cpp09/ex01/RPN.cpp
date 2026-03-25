/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:48:35 by romukena          #+#    #+#             */
/*   Updated: 2026/03/25 18:31:16 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {};
RPN::~RPN() {};
RPN::RPN(const RPN &other) {
	if (this != &other) {
		this->array = other.array;
	}
}

RPN &RPN ::operator=(const RPN &other) {
	if (this != &other) {
		this->array = other.array;
	}
	return *this;
}

std::stack<std::string> RPN::getArray() {
	return this->array;
}

RPN ::RPN(char *s) {
	std::string str(s);
	size_t first;
	size_t last;
	size_t i = 0;
	while (str[i]) {
		while (isspace(str[i]) != 0 && str[i]) {
			i++;
		}
		if (isspace(str[i]) == 0) {
			first = i;
		}
		while (isspace(str[i]) == 0 && str[i]) {
			i++;
		}
		if (isspace(str[i]) != 0 || str[i] == '\0') {
			last = i;
			std::string strToAdd = str.substr(first, (last - first));
			this->array.push(strToAdd);
		}
		while (isspace(str[i]) != 0) {
			i++;
		}
	}
};

void RPN::showElement() {
	RPN tmp = *this;
	std::stack<std::string> v = tmp.getArray();
	while (!v.empty()) {
		std::cout << v.top() << std::endl;
		v.pop();
	}
};

bool isInt(std::string a) {
	if (a.length() > 1)
		return false;
	if (isdigit(atoi(a.c_str())))
		return true;
	return false;
}

bool isOperator(std::string a) {
	if (a.length() > 1)
		return false;
	if ("+" == a || "-" == a || "/" == a || "*")
		return true;
	return false;
}

bool RPN::isValid() {
	RPN tmp = *this;
	std::stack<std::string> v = tmp.getArray();
	std::string val1 = v.top();
	v.pop();
	std::string val2 = v.top();
	v.pop();
	if (!isInt(val1) || !isInt(val2)) {
		return false;
	}
}