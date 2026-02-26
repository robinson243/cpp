/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:48:14 by romukena          #+#    #+#             */
/*   Updated: 2026/02/26 16:59:35 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Form {
  private:
	const std::string _name;
	bool _signed;
	const int _execGrade;
	const int _signGrade;

  public:
	Form();
	~Form();
	Form(const Form &other);
	Form &operator=(const Form &other);
	Form(std::string _newName,
		 bool _isSigned,
		 int _newExGrade,
		 int _newSiGrade);
	std::string getName();
	bool getSigned();
	int getExecGrade();
	int getSignGrade();
	friend std::ostream &operator<<(std::ostream &os, Form &object);
	void beSigned(Bureaucrat object);
	class GradeTooHighException : public std::exception {
	  public:
		virtual const char *what() const throw() {
			return "grade too high";
		}
	};

	class GradeTooLowException : public std::exception {
	  public:
		virtual const char *what() const throw() {
			return "grade too low";
		}
	};
};

#endif