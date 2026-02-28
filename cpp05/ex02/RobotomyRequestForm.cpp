/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 01:15:09 by romukena          #+#    #+#             */
/*   Updated: 2026/02/28 11:27:19 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : Aform("No name", 45, 72)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: Aform(other)
{
}

RobotomyRequestForm &
RobotomyRequestForm ::operator=(const RobotomyRequestForm &other)
{
	Aform::operator=(other);
	return *this;
}
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: Aform(target, 45, 72)
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	srand(time(NULL));
	int randomNum = rand() % 2;
	if (!this->getSigned())
	{
		std::cerr << this->getName() << " is not signed !" << std::endl;
		return;
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
	else
	{
		std::cerr << this->getName() << " failed to be robotomized" << std::endl;
	}
}