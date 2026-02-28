/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:40:05 by romukena          #+#    #+#             */
/*   Updated: 2026/02/28 16:24:43 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Aform.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>

int main() {
	Intern intern;
	Bureaucrat bob("Bob", 126);

	Aform *form;

	// Test shrubbery (Bob peut signer 126<145, PAS exec 126<137)
	form = intern.makeForm("shrubbery creation", "home");
	if (form) {
		form->beSigned(bob);
		bob.executeForm(*form);
		// delete form;
	}

	// Test unknown
	form = intern.makeForm("unknown form", "test");
	if (form)
		delete form;

	return 0;
}
