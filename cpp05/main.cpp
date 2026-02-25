/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:02:40 by romukena          #+#    #+#             */
/*   Updated: 2026/02/25 14:10:26 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	std::cout << "=== TESTS GETTERS ===\n";
	Bureaucrat a("Bob", 42);
	std::cout << a.getName() << std::endl;
	std::cout << a.getGrade() << std::endl;

	std::cout << "=== TESTS INCREMENT/DECREMENT ===\n";

	// Test 1: grade normal
	Bureaucrat normal("Normal", 75);
	std::cout << "Avant: " << normal.getGrade() << std::endl;

	normal.incrementGrade();
	std::cout << "Après ++: " << normal.getGrade() << std::endl;

	normal.decrementGrade();
	std::cout << "Après --: " << normal.getGrade() << std::endl;

	std::cout << "\n=== TESTS LIMITES ===\n";

	// Test 2: MAX grade (1)
	try {
		Bureaucrat max("Max", 1);
		std::cout << "Max avant: " << max.getGrade() << std::endl;
		max.incrementGrade();
		std::cout << "ERREUR: pas d'exception !" << std::endl;
	} catch (std::exception &e) {
		std::cout << "✓ MAX grade OK: " << e.what() << std::endl;
	}

	// Test 3: MIN grade (150)
	try {
		Bureaucrat min("Min", 150);
		std::cout << "Min avant: " << min.getGrade() << std::endl;
		min.decrementGrade();
		std::cout << "ERREUR: pas d'exception !" << std::endl;
	} catch (std::exception &e) {
		std::cout << "✓ MIN grade OK: " << e.what() << std::endl;
	}

	std::cout << normal << std::endl;
	return 0;
}
