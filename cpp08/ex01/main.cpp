/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:30:33 by romukena          #+#    #+#             */
/*   Updated: 2026/03/28 14:34:33 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
	// Span sp = Span(5);
	// sp.addNumber(6);
	// sp.addNumber(3);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);
	// Span o(5);
	// // o.addNumber(sp.getNum().begin(), sp.getNum().end())
	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;

	// Remplissage par plage d'itérateurs
	std::vector<int> source;
	for (int i = 0; i < 10000; i++)
		source.push_back(rand());

	Span big = Span(10000);
	big.addNumber(source.begin(), source.end());
	std::cout << "Shortest: " << big.shortestSpan() << std::endl;
	std::cout << "Longest: " << big.longestSpan() << std::endl;
	return 0;
}