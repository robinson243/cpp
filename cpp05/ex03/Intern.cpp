/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:59:30 by romukena          #+#    #+#             */
/*   Updated: 2026/02/28 16:22:36 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
}

Intern::~Intern() {
}

// Intern::Intern(const Intern &other) {
// }

// Intern &Intern::operator=(const Intern &other) {
// 	if (this != &other) {
// 		;
// 	}
// 	return *this;
// }

Aform *Intern::makeForm(const std::string &form, const std::string &target) {
	std::string stringForm[3] = { "presidential pardon",
								  "robotomy request",
								  "shrubbery creation" };
	int i = 0;
	while (i < 3) {
		if (stringForm[i] == form)
			break;
		i++;
	}
	Aform *f = NULL;
	switch (i) {
	case 0: {
		f = new PresidentialPardonForm(target);
		break;
	}
	case 1: {
		f = new RobotomyRequestForm(target);
		break;
	}
	case 2: {
		f = new ShrubberyCreationForm(target);
		break;
	}

	default: {
		std::cerr << "This " << form << " don't exist" << std::endl;
		break;
	}
	}
	if (!f)
		return NULL;
	std::cout << "Intern creates " << form << std::endl;
	return f;
}