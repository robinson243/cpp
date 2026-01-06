/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:01:39 by romukena          #+#    #+#             */
/*   Updated: 2026/01/06 01:44:58 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::~Harl() {}
Harl::Harl() {}

void Harl::complain(std::string level)
{
	void (Harl::*ptr_to_function[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string array[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	while (i < 4)
	{
		if (array[i] == level)
			break;
		i++;
	}
	switch (i)
	{
	case 0:
		(this->*ptr_to_function[0])();
		// fall through 
	case 1:
		(this->*ptr_to_function[1])();
		// fall through 
	case 2:
		(this->*ptr_to_function[2])();
		// fall through 
	case 3:
		(this->*ptr_to_function[3])();
		// fall through 
		break;
	default:
		std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

void Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.I really do !" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}