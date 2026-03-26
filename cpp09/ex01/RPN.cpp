/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:48:35 by romukena          #+#    #+#             */
/*   Updated: 2026/03/26 15:16:47 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {};
RPN::~RPN() {};
RPN::RPN(const RPN &other) {
	if (this != &other) {
		this->array = other.array;
		this->number = other.number;
		this->op = other.op;
	}
}

RPN &RPN ::operator=(const RPN &other) {
	if (this != &other) {
		this->array = other.array;
		this->number = other.number;
		this->op = other.op;
	}
	return *this;
}

std::stack<std::string> RPN::getArray() {
	return this->array;
}

std::stack<std::string> RPN::getNumber() {
	return this->number;
}

std::stack<std::string> RPN::getOp() {
	return this->op;
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
	RPN tmp(*this);
	std::stack<std::string> v = tmp.getArray();
	std::stack<std::string> op = tmp.getOp();
	std::stack<std::string> num = tmp.getNumber();

	std::cout << "my array stack" << std::endl;
	while (!v.empty()) {
		std::cout << v.top() << std::endl;
		v.pop();
	}
	std::cout << "my number stack" << std::endl;
	while (!num.empty()) {
		std::cout << num.top() << std::endl;
		num.pop();
	}
	std::cout << "my operator stack" << std::endl;
	while (!op.empty()) {
		std::cout << op.top() << std::endl;
		op.pop();
	}
};

bool isInt(std::string a) {
	if (a.length() > 1)
		return false;
	if (isdigit(a[0])) {
		return true;
	}
	return false;
}

bool isOperator(std::string a) {
	if (a.length() > 1)
		return false;
	if ("+" == a || "-" == a || "/" == a || "*")
		return true;
	return false;
}

void RPN::goodOrder() {
	std::stack<int> s;
	std::stack<int> temp;

	while (!s.empty()) {
		temp.push(s.top());
		s.pop();
	}

	s = temp;
}

bool RPN::isValid() {
	this->goodOrder();
	std::stack<std::string> &v = array;
	std::stack<std::string> &opi = op;
	std::stack<std::string> &num = number;
	while (!v.empty()) {
		if (isInt(v.top())) {
			num.push(v.top());
		} else if (isOperator(v.top())) {
			opi.push(v.top());
		} else
			return false;
		v.pop();
	}
	return true;
}