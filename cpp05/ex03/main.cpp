/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:40:05 by romukena          #+#    #+#             */
/*   Updated: 2026/03/01 10:46:21 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>

int main()
{
	Intern intern;
	Bureaucrat bob("Bob", 1);

	AForm *form;

	form = intern.makeForm("shrubbery creation", "home");
	if (form)
	{
		form->beSigned(bob);
		bob.executeForm(*form);
	}

	form = intern.makeForm("robotomy request", "home2");
	if (form)
	{
		form->beSigned(bob);
		bob.executeForm(*form);
	}

	form = intern.makeForm("presidential pardon", "home3");
	if (form)
	{
		form->beSigned(bob);
		bob.executeForm(*form);
	}
	// Test unknown
	form = intern.makeForm("unknown form", "test");
	if (form)
		delete form;

	return 0;
}
