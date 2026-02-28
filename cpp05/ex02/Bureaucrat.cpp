/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:11:55 by romukena          #+#    #+#             */
/*   Updated: 2026/02/28 00:47:53 by romukena         ###   ########.fr       */
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
		;
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
	os << object.getName() << ", bureaucrat grade " << object.getGrade();
	return os;
}

void Bureaucrat::signForm(Aform &object)
{
	if (!object.getName().empty())
	{
		try
		{
			if (this->getGrade() <= object.getSignGrade())
			{
				object.beSigned(*this);
			}
			std::cout << this->getName() << " signed " << object.getName();
		}
		catch (const std::exception &e)
		{
			std::cerr << this->getName() << " couldn’t sign "
					  << object.getName() << " because " << e.what() << '\n';
		}
	}
}