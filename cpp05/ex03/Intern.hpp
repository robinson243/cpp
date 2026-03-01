/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:56:00 by romukena          #+#    #+#             */
/*   Updated: 2026/03/01 10:34:07 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern
{
public:
    Intern();
    ~Intern();
    // Intern(const Intern &other);
    // Intern &operator=(const Intern &other);
    AForm* makeForm(const std::string &form, const std::string &target);
};


#endif