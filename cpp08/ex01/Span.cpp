/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:49:01 by romukena          #+#    #+#             */
/*   Updated: 2026/03/17 18:34:21 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {};

Span::~Span() {};

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		copy(this->_number.begin(), this->_number.end(), other._number.begin());
	}
	return *this;
}

Span::Span(const Span &other) {
	if (this != &other) {
		copy(this->_number.begin(), this->_number.end(), other._number.begin());
	}
}

Span::Span(unsigned int n) : _number(static_cast<int>(n)) {
}

std::vector<int>::iterator Span::shortestSpan() {
	return min_element(this->_number.begin(), this->_number.end());
}

std::vector<int>::iterator Span::longestSpan() {
	return max_element(this->_number.begin(), this->_number.end());
}

void Span::addNumber(unsigned int n) {
	if (this->_number.size() >= INT_MAX)
		return;
	this->_number.push_back(n);
}
