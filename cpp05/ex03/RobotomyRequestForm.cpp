/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 01:15:09 by romukena          #+#    #+#             */
/*   Updated: 2026/03/12 17:21:06 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

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
	else
	{
		std::cerr << this->getName() << " failed to be robotomized"
				  << std::endl;
	}
}