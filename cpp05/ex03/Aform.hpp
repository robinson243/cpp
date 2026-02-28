/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aform.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 16:14:32 by romukena          #+#    #+#             */
/*   Updated: 2026/02/28 15:30:48 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP
class Bureaucrat;
#include <iostream>

class Aform
{
private:
	const std::string _name;
	bool _signed;
	const int _execGrade;
	const int _signGrade;

public:
	Aform();
	virtual ~Aform();
	Aform(const Aform &other);
	Aform &operator=(const Aform &other);
	Aform(std::string _newName, int _newExGrade, int _newSiGrade);
	std::string getName() const;
	bool getSigned() const;
	int getExecGrade() const;
	int getSignGrade() const;
	friend std::ostream &operator<<(std::ostream &os, Aform &object);
	void beSigned(Bureaucrat &object);
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "grade too high";
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "grade too low";
		}
	};
	virtual void execute(Bureaucrat const &executor) const = 0;
};

#endif