/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:48:35 by romukena          #+#    #+#             */
/*   Updated: 2026/03/26 17:23:28 by romukena         ###   ########.fr       */
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
	RPN tmp(*this);
	std::stack<std::string> v = tmp.getArray();

	std::cout << "my array stack" << std::endl;
	while (!v.empty()) {
		std::cout << v.top() << std::endl;
		v.pop();
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
	if ("+" == a || "-" == a || "/" == a || "*" == a)
		return true;
	return false;
}

void RPN::goodOrder() {
	std::stack<std::string> &s = this->array;
	std::stack<std::string> temp;
	while (!s.empty()) {
		temp.push(s.top());
		s.pop();
	}

	s = temp;
}

bool RPN::isValid() {
	std::stack<std::string> v = this->getArray();
	while (!v.empty()) {
		if (!isInt(v.top()) && !isOperator(v.top())) {
			return false;
		}
		v.pop();
	}
	return true;
}

void RPN::solution() {
	this->goodOrder();
	std::stack<std::string> v = this->array;
	std::stack<std::string> o;
	while (!v.empty()) {
		if (isInt(v.top()))
			o.push(v.top());
		else {
			std::string a = o.top();
			o.pop();
			std::string b = o.top();
			o.pop();
			std::ostringstream s;
			if (v.top() == "+") {
				int num = atoi(b.c_str()) + atoi(a.c_str());
				s << num;
				o.push(s.str());
			} else if (v.top() == "-") {
				int num = atoi(b.c_str()) - atoi(a.c_str());
				s << num;
				o.push(s.str());
			} else if (v.top() == "*") {
				int num = atoi(b.c_str()) * atoi(a.c_str());
				s << num;
				o.push(s.str());
			} else if (v.top() == "/") {
				int num = atoi(b.c_str()) / atoi(a.c_str());
				s << num;
				o.push(s.str());
			}
		}
		v.pop();
	}
	if (o.size() > 1)
	{
		std::cerr << "Error" << std::endl;
		return ;	
	}
	std::cout << o.top() << std::endl;
}
