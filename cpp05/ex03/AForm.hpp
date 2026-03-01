/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aform.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 16:14:32 by romukena          #+#    #+#             */
/*   Updated: 2026/03/01 10:34:31 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP
class Bureaucrat;
#include <iostream>

class AForm
{
private:
	const std::string _name;
	bool _signed;
	const int _execGrade;
	const int _signGrade;

public:
	AForm();
	virtual ~AForm();
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	AForm(std::string _newName, int _newExGrade, int _newSiGrade);
	std::string getName() const;
	bool getSigned() const;
	int getExecGrade() const;
	int getSignGrade() const;
	friend std::ostream &operator<<(std::ostream &os, AForm &object);
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