/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 16:51:27 by romukena          #+#    #+#             */
/*   Updated: 2026/03/12 16:08:01 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: _name("No name"), _signed(false), _execGrade(150), _signGrade(150)
{
}

AForm::~AForm()
{
}

AForm::AForm(const AForm &other)
	: _name(other._name), _signed(other._signed), _execGrade(other._execGrade),
	  _signGrade(other._signGrade)
{
}

AForm::AForm(std::string _newName, int _newExGrade, int _newSiGrade)
	: _name(_newName), _signed(false), _execGrade(_newExGrade),
	  _signGrade(_newSiGrade)
{
	if (_newSiGrade < 1 || _newExGrade < 1)
		throw GradeTooHighException();
	else if (_newSiGrade > 150 || _newExGrade > 150)
		throw GradeTooLowException();
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		_signed = other._signed;
	return *this;
}

std::string AForm::getName() const
{
	return this->_name;
}

bool AForm::getSigned() const
{
	return this->_signed;
}

int AForm::getExecGrade() const
{
	return this->_execGrade;
}

int AForm::getSignGrade() const
{
	return this->_signGrade;
}

std::ostream &operator<<(std::ostream &os, AForm &object)
{
	if (!object.getName().empty())
	{
		os << "AForm " << object.getName()
		   << " is signed : " << object.getSigned()
		   << " execGrade : " << object.getExecGrade()
		   << " and signGrade : " << object.getSignGrade();
	}
	return os;
}

void AForm::beSigned(Bureaucrat &object)
{

	if (object.getGrade() <= this->getSignGrade())
	{
		this->_signed = true;
	}
	else
		throw GradeTooLowException();
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:11:55 by romukena          #+#    #+#             */
/*   Updated: 2026/03/12 16:23:58 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("No Name"), _grade(150)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: _name(other._name), _grade(other._grade)
{
}

Bureaucrat::Bureaucrat(std::string _otherName, int _otherGrade)
	: _name(_otherName)
{
	if (_otherGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_otherGrade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = _otherGrade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return *this;
}

std::string Bureaucrat::getName()
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &object)
{
	os << object.getName() << ", bureaucrat grade " << object.getGrade() << ".";
	return os;
}

void Bureaucrat::signForm(AForm &object)
{
	try
	{
		object.beSigned(*this);
		std::cout << this->getName() << " signed " << object.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << this->getName() << " couldn’t sign "
				  << object.getName() << " because " << e.what() << '\n';
	}
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		std::cout << this->getName() << " executed " << form.getName()
				  << std::endl;
		form.execute(*this);
	}
	catch (const std::exception &e)
	{
		std::cout << this->getName() << " cannot execute " << form.getName()
				  << ": " << e.what() << std::endl;
	}
}/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:59:30 by romukena          #+#    #+#             */
/*   Updated: 2026/03/01 10:34:07 by romukena         ###   ########.fr       */
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

AForm *Intern::makeForm(const std::string &form, const std::string &target) {
	std::string stringForm[3] = { "presidential pardon",
								  "robotomy request",
								  "shrubbery creation" };
	int i = 0;
	while (i < 3) {
		if (stringForm[i] == form)
			break;
		i++;
	}
	AForm *f = NULL;
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
}/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 13:42:49 by romukena          #+#    #+#             */
/*   Updated: 2026/03/12 16:13:28 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("No name", 5, 25) {
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm &other)
	: AForm(other) {
}

PresidentialPardonForm &
PresidentialPardonForm ::operator=(const PresidentialPardonForm &other) {
	AForm::operator=(other);
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm(target, 5, 25)  {
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!this->getSigned()) {
		throw GradeTooLowException();
	}

	if (executor.getGrade() > this->getExecGrade()) {
		throw GradeTooLowException();
	}
	std::cout << this->getName() << " has been pardonned by Zaphod Beeblebrox !"
			  << std::endl;
}/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 01:15:09 by romukena          #+#    #+#             */
/*   Updated: 2026/03/12 16:25:54 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("No name", 45, 72)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other)
{
}

RobotomyRequestForm &
RobotomyRequestForm ::operator=(const RobotomyRequestForm &other)
{
	AForm::operator=(other);
	return *this;
}
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm(target, 45, 72)
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	srand(time(NULL));
	int randomNum = rand() % 2;
	if (!this->getSigned())
	{
		throw GradeTooLowException();
	}

	if (executor.getGrade() > this->getExecGrade())
	{
		throw GradeTooLowException();
	}
	std::cout << "Vrrrrrrrrrrrrrrrrrrr" << std::endl;
	if (randomNum == 1)
	{
		std::cout << this->getName() << " has been robotomized" << std::endl;
	}
}/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:30:57 by romukena          #+#    #+#             */
/*   Updated: 2026/03/12 16:26:15 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("No name", 137, 145)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other)
{
}

ShrubberyCreationForm &
ShrubberyCreationForm ::operator=(const ShrubberyCreationForm &other)
{
	AForm::operator=(other);
	return *this;
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm(target, 137, 145)
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
	{
		throw GradeTooLowException();
	}
	if (executor.getGrade() > this->getExecGrade())
	{
		throw GradeTooLowException();
	}
	std::string name = this->getName() + "_shrubbery";
	std::ofstream outfile(name.c_str());

	if (!outfile)
	{
		return;
	}
	for (int i = 0; i < 5; i++)
	{
		outfile << "           &&& &&  & &&\n"
				   "       && &\\/&\\|& ()|/ @, &&\n"
				   "       &\\/(/&/&||/& /_/)_&/_&\n"
				   "    &() &\\/&|()|/&\\/ '%\" & ()\n"
				   "   &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
				   " &&   && & &| &| /& & % ()& /&&\n"
				   "  ()&_---()&\\&\\|&&-&&--%---()~\n"
				   "      &&     \\||| \n"
				   "              |||\n"
				   "              |||\n"
				   "              |||\n"
				   "              |||\n"
				   "        , -=-~  .-^- _\n";
	}

	outfile.close();
}/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:40:05 by romukena          #+#    #+#             */
/*   Updated: 2026/03/12 16:22:11 by romukena         ###   ########.fr       */
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
		delete form;
	}

	form = intern.makeForm("robotomy request", "home2");
	if (form)
	{
		form->beSigned(bob);
		bob.executeForm(*form);
		delete form;
	}

	form = intern.makeForm("presidential pardon", "home3");
	if (form)
	{
		form->beSigned(bob);
		bob.executeForm(*form);
		delete form;
	}
	// Test unknown
	form = intern.makeForm("unknown form", "test");
	if (form)
		delete form;

	return 0;
}
