/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:48:01 by romukena          #+#    #+#             */
/*   Updated: 2026/02/26 17:24:26 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	: _name("No name"), _signed(false), _execGrade(150), _signGrade(150) {
}

Form::~Form() {
}

Form::Form(std::string _newName,
		   bool _isSigned,
		   int _newExGrade,
		   int _newSiGrade)
	: _name(_newName), _signed(_isSigned), _execGrade(_newExGrade),
	  _signGrade(_newSiGrade) {
	if (_newSiGrade < 1 || _newExGrade < 1)
		throw GradeTooHighException();
	else if (_newSiGrade > 150 || _newExGrade > 150)
		throw GradeTooLowException();
}

Form &Form::operator=(const Form &other) {
	if (this != &other)
		*this = *&other;
	return *this;
}

std::string Form::getName() {
	return this->_name;
}

bool Form::getSigned() {
	return this->_signed;
}

int Form::getExecGrade() {
	return this->_execGrade;
}

int Form::getSignGrade() {
	return this->_signGrade;
}

std::ostream &operator<<(std::ostream &os, Form &object) {
	os << "Form " << object.getName() << " is signed : " << object.getSigned()
	   << " execGrade : " << object.getExecGrade()
	   << " and signGrade : " << object.getSignGrade();
	return os;
}

void Form::beSigned(Bureaucrat object)
{
    
}