/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:24:31 by romukena          #+#    #+#             */
/*   Updated: 2026/02/27 17:49:12 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Aform.hpp"
#include <iostream>

class ShrubberyCreationForm : public Aform {
  public:
	ShrubberyCreationForm(const std::string &target);
	virtual void execute(Bureaucrat const &executor);
};

#endif