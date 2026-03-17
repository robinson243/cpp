/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 13:08:50 by romukena          #+#    #+#             */
/*   Updated: 2026/03/17 13:32:05 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
private:
	Span();
	~Span();
	Span(const Span &other);
	Span &operator=(const Span &other);

public:
	Span(unsigned int n);
	std::vector<int>::iterator shortestSpan();
	std::vector<int>::iterator longestSpan();
	void addNumber();
};

#endif