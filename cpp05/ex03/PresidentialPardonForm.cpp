/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 13:42:49 by romukena          #+#    #+#             */
/*   Updated: 2026/02/28 15:39:11 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Aform("No name", 5, 25) {
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm &other)
	: Aform(other) {
}

PresidentialPardonForm &
PresidentialPardonForm ::operator=(const PresidentialPardonForm &other) {
	Aform::operator=(other);
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: Aform(target, 5, 25)  {
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!this->getSigned()) {
		std::cerr << this->getName() << " is not signed !" << std::endl;
		return;
	}

	if (executor.getGrade() > this->getExecGrade()) {
		throw GradeTooLowException();
	}
	std::cout << this->getName() << " has been pardonned by Zaphod Beeblebrox !"
			  << std::endl;
}