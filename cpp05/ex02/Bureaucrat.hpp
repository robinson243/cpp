/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:45:02 by romukena          #+#    #+#             */
/*   Updated: 2026/02/28 00:47:39 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Aform.hpp"
#include <iostream>

class Bureaucrat {
  private:
	const std::string _name;
	int _grade;

  public:
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	Bureaucrat(std::string _otherName, int _otherGrade);
	std::string getName();
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(Aform &object);
	friend std::ostream &operator<<(std::ostream &os, Bureaucrat &object);
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