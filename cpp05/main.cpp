/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:02:40 by romukena          #+#    #+#             */
/*   Updated: 2026/02/25 13:33:16 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat a("Bob", 42);
	std::cout << a.getName() << std::endl;
	std::cout << a.getGrade() << std::endl;

	try {
		Bureaucrat bad1("test", 0); // Doit catcher "grade too high"
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}