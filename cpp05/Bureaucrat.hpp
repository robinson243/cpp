/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:45:02 by romukena          #+#    #+#             */
/*   Updated: 2026/02/23 13:45:47 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

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
	int getGrade();
	void incrementGrade();
	void decrementGrade();
	Bureaucrat &operator<<(const Bureaucrat &other);
	void GradeTooHighException()
};

#endif