/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:48:01 by romukena          #+#    #+#             */
/*   Updated: 2026/02/26 14:50:02 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("No name"), _signed(false), _execGrade(0), _signGrade(0) {
}

Form::~Form() {}

Form::Form(std::string _newName, bool _isSigned, int _newExGrade, int _newSiGrade) : _name(_newName), _signed(_isSigned)
{
    if (_newSiGrade < 1 || _newExGrade < 1)
        throw GradeTooHighException();
    else if (_newSiGrade > 150 || _newExGrade > 150)
        throw GradeTooLowException();
    else {
        _execGrade = _newExGrade;
        _signGrade = _newSiGrade;
    }
}
