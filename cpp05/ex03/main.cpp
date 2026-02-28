/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:40:05 by romukena          #+#    #+#             */
/*   Updated: 2026/02/28 15:29:18 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "Aform.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>

int main() {
    Intern                someRandomIntern;
    Bureaucrat            bob("Bob", 126);
    
    Aform*                form;
    
    form = someRandomIntern.makeForm("shrubbery creation", "home");
    if (form)
        bob.executeForm(*form);
    delete form;
    
    form = someRandomIntern.makeForm("robotomy request", "Bob");
    if (form)
        bob.executeForm(*form);
    delete form;
    
    form = someRandomIntern.makeForm("presidential pardon", "first citizen");
    if (form)
        bob.executeForm(*form);
    delete form;
    
    return 0;
}
