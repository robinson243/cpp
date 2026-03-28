/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:49:01 by romukena          #+#    #+#             */
/*   Updated: 2026/03/28 12:30:36 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {};

Span::~Span() {};

Span &Span::operator=(const Span &other) {
	if (this != &other)
		_number = other._number;
	return *this;
}

Span::Span(const Span &other) {
	if (this != &other) {
		_number = other._number;
	}
}

Span::Span(unsigned int n) {
	_number.reserve(n);
}

int Span::shortestSpan() {
	std::vector<int> v = this->getNum();

	std::sort(v.begin(), v.end());
	int smallValue = INT_MAX;
	if (v.size() < 2)
		throw std::underflow_error("Not enough elements");
	for (std::vector<int>::size_type i = 1; i < v.size(); i++) {
		if ((v[i] - v[i - 1]) < smallValue) {
			smallValue = (v[i] - v[i - 1]);
		}
	}
	return smallValue;
}

int Span::longestSpan() {
	if (_number.size() < 2)
		throw std::underflow_error("Not enough elements");
	return (*std::max_element(this->_number.begin(), this->_number.end())
			- *std::min_element(this->_number.begin(), this->_number.end()));
}

void Span::addNumber(int n) {
	if (this->_number.size() >= this->_number.capacity())
		throw std::length_error("Container is full !");
	this->_number.push_back(n);
}

const std::vector<int> &Span::getNum() const {
	return _number;
}
