/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:11:55 by romukena          #+#    #+#             */
/*   Updated: 2026/02/23 13:31:38 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("No Name"), _grade(150) {
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: _name(other._name), _grade(other._grade) {
}

Bureaucrat::Bureaucrat(std::string _otherName, int _otherGrade)
	: _name(_otherName), _grade(_otherGrade) {
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other)
		*this = *&other;
	return *this;
}

std::string Bureaucrat::getName() {
	return (this->_name);
}

int Bureaucrat::getGrade() {
	return (this->_grade);
}