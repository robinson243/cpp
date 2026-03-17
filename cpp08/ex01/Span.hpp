/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 13:08:50 by romukena          #+#    #+#             */
/*   Updated: 2026/03/18 00:22:41 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include "limits.h"
#include <algorithm>
#include <iostream>
#include <vector>

class Span
{
private:
	std::vector<int> _number;

public:
	Span();
	Span &operator=(const Span &other);
	~Span();
	Span(const Span &other);
	Span(unsigned int n);
	int shortestSpan();
	int longestSpan();
	void addNumber(unsigned int n);
	friend std::ostream &operator<<(std::ostream &os, Span &other);
};

#endif