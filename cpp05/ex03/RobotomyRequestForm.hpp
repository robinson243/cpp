/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 01:11:27 by romukena          #+#    #+#             */
/*   Updated: 2026/02/28 01:41:56 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Aform.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

class RobotomyRequestForm : public Aform
{
public:
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	RobotomyRequestForm(const std::string &target);
	void execute(Bureaucrat const &executor) const;
};

#endif