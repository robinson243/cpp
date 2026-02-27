/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:48:14 by romukena          #+#    #+#             */
/*   Updated: 2026/02/27 14:53:34 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

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
	Form(std::string _newName, int _newExGrade, int _newSiGrade);
	std::string getName();
	bool getSigned();
	int getExecGrade();
	int getSignGrade();
	friend std::ostream &operator<<(std::ostream &os, Form &object);
	void beSigned(Bureaucrat &object);
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