/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:30:57 by romukena          #+#    #+#             */
/*   Updated: 2026/02/27 19:36:08 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Aform("No name", 137, 145) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: Aform(other) {
}

ShrubberyCreationForm &
ShrubberyCreationForm ::operator=(const ShrubberyCreationForm &other) {
	Aform::operator=(other);
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: Aform(target, 137, 145) {
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) {
	std::string name = this->getName().append("_shrubbery");
	std::ofstream outfile(name);

	for (int i = 0; i < 5; i++) {
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