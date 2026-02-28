/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:59:30 by romukena          #+#    #+#             */
/*   Updated: 2026/02/28 15:38:52 by romukena         ###   ########.fr       */
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
    // std::cout << "je suis la " << stringForm[0] << std::endl;
	switch (i) {
	case 0: {
		std::cout << "Intern creates " << form << std::endl;
		return new PresidentialPardonForm(target);
	}
	case 1: {
		std::cout << "Intern creates " << form << std::endl;
		return new RobotomyRequestForm(target);
	}
	case 2: {
		std::cout << "Intern creates " << form << std::endl;
		return new ShrubberyCreationForm(target);
	}

	default: {
		std::cerr << "This " << form << " don't exist" << std::endl;
		break;
	}
	}
	return NULL;
}