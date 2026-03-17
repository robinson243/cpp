/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:49:01 by romukena          #+#    #+#             */
/*   Updated: 2026/03/18 00:23:44 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {};

Span::~Span() {};

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		std::copy(other._number.begin(), other._number.end(), this->_number.begin());
	}
	return *this;
}

Span::Span(const Span &other)
{
	if (this != &other)
	{
		std::copy(other._number.begin(), other._number.end(), this->_number.begin());
	}
}

Span::Span(unsigned int n) : _number(static_cast<int>(n))
{
}

int Span::shortestSpan()
{
	return *min_element(this->_number.begin(), this->_number.end());
}
int Span::longestSpan()
{
	return *max_element(this->_number.begin(), this->_number.end());
}

void Span::addNumber(unsigned int n)
{
	if (this->_number.size() >= INT_MAX)
		return;
	this->_number.push_back(n);
}
