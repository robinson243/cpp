/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:49:01 by romukena          #+#    #+#             */
/*   Updated: 2026/03/21 15:54:56 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {};

Span::~Span() {};

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		_number.resize(other._number.size());
		std::copy(
			other._number.begin(), other._number.end(), this->_number.begin());
	}
	return *this;
}

Span::Span(const Span &other) {
	if (this != &other) {
		_number.resize(other._number.size());
		std::copy(
			other._number.begin(), other._number.end(), this->_number.begin());
	}
}

Span::Span(unsigned int n) {
	_number.reserve(n);
}

int Span::shortestSpan() {
	std::vector<int> v = this->getNum();

	sort(v.begin(), v.end());
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
	return (*max_element(this->_number.begin(), this->_number.end())
			- *min_element(this->_number.begin(), this->_number.end()));
}

void Span::addNumber(unsigned int n) {
	if (this->_number.size() >= this->_number.capacity())
		throw std::length_error("Container is full !");
	this->_number.push_back(n);
}

std::vector<int> Span::getNum() {
	return this->_number;
}
