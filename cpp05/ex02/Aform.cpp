/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aform.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 16:51:27 by romukena          #+#    #+#             */
/*   Updated: 2026/02/27 17:16:12 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Aform.hpp"
#include "Bureaucrat.hpp"

Aform::Aform()
	: _name("No name"), _signed(false), _execGrade(150), _signGrade(150) {
}

Aform::~Aform() {
}

Aform::Aform(const Aform &other)
	: _name(other._name), _signed(other._signed), _execGrade(other._execGrade),
	  _signGrade(other._signGrade) {
}

Aform::Aform(std::string _newName, int _newExGrade, int _newSiGrade)
	: _name(_newName), _signed(false), _execGrade(_newExGrade),
	  _signGrade(_newSiGrade) {
	if (_newSiGrade < 1 || _newExGrade < 1)
		throw GradeTooHighException();
	else if (_newSiGrade > 150 || _newExGrade > 150)
		throw GradeTooLowException();
}

Aform &Aform::operator=(const Aform &other) {
	if (this != &other) {
		;
	}
	return *this;
}

std::string Aform::getName() {
	return this->_name;
}

bool Aform::getSigned() {
	return this->_signed;
}

int Aform::getExecGrade() {
	return this->_execGrade;
}

int Aform::getSignGrade() {
	return this->_signGrade;
}

std::ostream &operator<<(std::ostream &os, Aform &object) {
	if (!object.getName().empty()) {
		os << "Aform " << object.getName()
		   << " is signed : " << object.getSigned()
		   << " execGrade : " << object.getExecGrade()
		   << " and signGrade : " << object.getSignGrade();
	}
	return os;
}

void Aform::beSigned(Bureaucrat &object) {
	if (!object.getName().empty()) {
		if (object.getGrade() <= this->getSignGrade()) {
			this->_signed = true;
		} else
			throw GradeTooLowException();
	}
}
