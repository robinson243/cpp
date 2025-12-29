/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 12:08:23 by romukena          #+#    #+#             */
/*   Updated: 2025/12/29 14:39:09 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

Contact Add()
{
	std::string firstname;
	std::string lastname;
	std::string nickmame;
	std::string input;
	std::string secret;
	std::cout << "Ecris le champ firstname : ";
	std::getline(std::cin, firstname);
	std::cout << "Ecris le champ lastname : ";
	std::getline(std::cin, lastname);
	std::cout << "Ecris le champ nickname : ";
	std::getline(std::cin, nickmame);
	while (1)
	{
		std::cout << "Ecris le champ number sans espace : ";
		std::getline(std::cin, input);
		if (input.length() < 10)
			break;
	}
	std::cout << "Ecris le champ darkest secret : ";
	std::getline(std::cin, secret);
	Contact perso(firstname, lastname, nickmame, input, secret);
	return (perso);
}

std::string truncate(std::string s)
{
	std::string dest;
	if (s.length() > 10)
	{
		dest = s.substr(0, 9);
		dest += ".";
		return dest;
	}
	return (s);
}

void Search(Phonebook repertoire, std::string number)
{
	Contact *pb = repertoire.get_repertoire();
	int index = atoi(number.c_str());

	if (number.size() != 1 || !std::isdigit(number[0]))
	{
		std::cout << "Index non identifié" << std::endl;
		return;
	}
	if (index < 0 || index > 7)
	{
		std::cout << "Index non identifié" << std::endl;
		return;
	}
	if (index > repertoire.get_index())
	{
		std::cout << "Index non identifié" << std::endl;
		return;
	}
	std::cout << std::setw(10);
	std::cout << index;
	std::cout << "|";

	std::cout << std::setw(10);
	std::cout << truncate(pb[index].get_firstname());
	std::cout << "|";

	std::cout << std::setw(10);
	std::cout << truncate(pb[index].get_lastname());
	std::cout << "|";

	std::cout << std::setw(10);
	std::cout << truncate(pb[index].get_nickname());
	std::cout << "|" << std::endl;
	return;
}

void print_all(Phonebook poloe)
{
	Contact *pb = poloe.get_repertoire();
	int i = 0;
	while (i < poloe.get_index())
	{
		std::cout << pb[i].get_firstname() << std::endl;
		i++;
	}
	return;
}