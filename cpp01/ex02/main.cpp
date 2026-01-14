/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 21:04:50 by romukena          #+#    #+#             */
/*   Updated: 2026/01/14 18:05:15 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string word = "HI THIS IS BRAIN";
	std::string *stringPTR = &word;
	std::string &stringREF = word;

	std::cout << "L'adresse de la string " << &word << std::endl;
	std::cout << "L'adresse de la stringPTR " << &stringPTR << std::endl;
	std::cout << "L'adresse de la stringREF " << &stringREF << std::endl;

	std::cout << "-----------------------" << std::endl;

	std::cout << "La valeur de la string " << word << std::endl;
	std::cout << "La valeur de la stringPTR " << *stringPTR << std::endl;
	std::cout << "La valeur de la stringREF " << stringREF << std::endl;
}