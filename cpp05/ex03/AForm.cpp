/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aform.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 16:51:27 by romukena          #+#    #+#             */
/*   Updated: 2026/03/01 10:34:07 by romukena         ###   ########.fr       */
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
	delete this;
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
	{
		;
	}
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
	if (!object.getName().empty())
	{
		if (object.getGrade() <= this->getSignGrade())
		{
			this->_signed = true;
		}
		else
			throw GradeTooLowException();
	}
}
