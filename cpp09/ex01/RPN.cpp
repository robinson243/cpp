/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:48:35 by romukena          #+#    #+#             */
/*   Updated: 2026/03/25 17:22:01 by romukena         ###   ########.fr       */
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

int ft_isspace(int c) {
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

RPN ::RPN(char *s) {
	std::string str(s);
	size_t first;
	size_t last;
	size_t i = 0;
	while (str[i]) {
		while (ft_isspace(str[i]) != 0 && str[i]) {
			i++;
		}
		if (ft_isspace(str[i]) == 0) {
			first = i;
		}
		while (ft_isspace(str[i]) == 0 && str[i]) {
			i++;
		}
		if (ft_isspace(str[i]) != 0 || str[i] == '\0') {
			last = i;
			std::string strToAdd = str.substr(first, (last - first));
			this->array.push(strToAdd);
		}
		while (ft_isspace(str[i]) != 0) {
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