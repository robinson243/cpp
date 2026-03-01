/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:30:57 by romukena          #+#    #+#             */
/*   Updated: 2026/03/01 10:34:07 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("No name", 137, 145)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other)
{
}

ShrubberyCreationForm &
ShrubberyCreationForm ::operator=(const ShrubberyCreationForm &other)
{
	AForm::operator=(other);
	return *this;
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm(target, 137, 145)
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
	{
		std::cerr << this->getName() << " is not signed !" << std::endl;
		return;
	}

	if (executor.getGrade() > this->getExecGrade())
	{
		throw GradeTooLowException();
	}
	std::string name = this->getName() + "_shrubbery";
	std::ofstream outfile(name.c_str());

	if (!outfile)
	{
		std::cerr << " Can not open the file : " << name << std::endl;
		return;
	}
	for (int i = 0; i < 5; i++)
	{
		outfile << "           &&& &&  & &&\n"
				   "       && &\\/&\\|& ()|/ @, &&\n"
				   "       &\\/(/&/&||/& /_/)_&/_&\n"
				   "    &() &\\/&|()|/&\\/ '%\" & ()\n"
				   "   &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
				   " &&   && & &| &| /& & % ()& /&&\n"
				   "  ()&_---()&\\&\\|&&-&&--%---()~\n"
				   "      &&     \\||| \n"
				   "              |||\n"
				   "              |||\n"
				   "              |||\n"
				   "              |||\n"
				   "        , -=-~  .-^- _\n";
	}

	outfile.close();
}