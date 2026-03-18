/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:49:01 by romukena          #+#    #+#             */
/*   Updated: 2026/03/18 16:25:03 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {};

Span::~Span() {};

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		std::copy(
			other._number.begin(), other._number.end(), this->_number.begin());
	}
	return *this;
}

Span::Span(const Span &other) {
	if (this != &other) {
		std::copy(
			other._number.begin(), other._number.end(), this->_number.begin());
	}
}

Span::Span(unsigned int n) {
	_number.reserve(n);
}

int Span::shortestSpan() {
	std::vector<int> v = this->getNum();
	std::vector<int> diff(this->getNum().size());

	sort(v.begin(), v.end());
	int smallValue;
	std::vector<int>::size_type i = 0;
	std::vector<int>::size_type j = 1;
	smallValue = v[j] - v[i];
	for (std::vector<int>::size_type i = 0; i < diff.size(); i++) {
		for (std::vector<int>::size_type j = i + 1; j < diff.size(); j++) {
			if (smallValue > (v[j] - v[i])) {
				smallValue = (v[j] - v[i]);
			}
		}
	}
	return smallValue;
}
int Span::longestSpan() {
	return (*max_element(this->_number.begin(), this->_number.end())
			- *min_element(this->_number.begin(), this->_number.end()));
}

void Span::addNumber(unsigned int n) {
	if (this->_number.size() >= INT_MAX)
		return;
	this->_number.push_back(n);
}

std::vector<int> Span::getNum() {
	return this->_number;
}
