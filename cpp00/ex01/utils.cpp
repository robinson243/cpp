/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 12:08:23 by romukena          #+#    #+#             */
/*   Updated: 2026/01/10 14:29:14 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

Contact Add()
{
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string input;
	std::string secret;

	do
	{
		std::cout << "Ecris le champ firstname : ";
		if (!std::getline(std::cin, firstname))
			std::exit(0);
	} while (firstname.empty());

	do
	{
		std::cout << "Ecris le champ lastname : ";
		if (!std::getline(std::cin, lastname))
			std::exit(0);
	} while (lastname.empty());

	do
	{
		std::cout << "Ecris le champ nickname : ";
		if (!std::getline(std::cin, nickname))
			std::exit(0);
	} while (nickname.empty());

	do
	{
		std::cout << "Ecris le champ number sans espace : ";
		if (!std::getline(std::cin, input))
			std::exit(0);
	} while (input.empty());

	do
	{
		std::cout << "Ecris le champ darkest secret : ";
		if (!std::getline(std::cin, secret))
			std::exit(0);
	} while (secret.empty());

	Contact perso(firstname, lastname, nickname, input, secret);
	return perso;
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

void print_contact(Contact pb)
{
	std::cout << "First Name: " << pb.get_firstname() << std::endl;
	std::cout << "Last Name: " << pb.get_lastname() << std::endl;
	std::cout << "Nickname: " << pb.get_nickname() << std::endl;
	std::cout << "Phone Number: " << pb.get_phone() << std::endl;
	std::cout << "Darkest Secret: " << pb.get_secret() << std::endl;
}

void print_all(Phonebook poloe)
{
	Contact *pb = poloe.get_repertoire();
	int i = 0;
	int index = poloe.get_index();
	if (index > 8)
		index = 8;
	while (i < index)
	{
		std::cout << std::setw(10);
		std::cout << i;
		std::cout << "|";

		std::cout << std::setw(10);
		std::cout << truncate(pb[i].get_firstname());
		std::cout << "|";

		std::cout << std::setw(10);
		std::cout << truncate(pb[i].get_lastname());
		std::cout << "|";

		std::cout << std::setw(10);
		std::cout << truncate(pb[i].get_nickname());
		std::cout << "|" << std::endl;
		i++;
	}
	return;
}
void Search(Phonebook repertoire)
{
	Contact *pb = repertoire.get_repertoire();

	if (repertoire.get_index() == 0)
	{
		std::cout << "Pas de contact encore cree" << std::endl;
		return;
	}

	print_all(repertoire);

	std::cout << "Ecris un index > ";
	std::string number;

	if (!std::getline(std::cin, number))
		return;
	if (number.empty())
	{
		std::cout << "Index non identifié" << std::endl;
		return;
	}

	std::stringstream ss(number);
	int index;

	if (!(ss >> index))
	{
		std::cout << "Index non identifié" << std::endl;
		return;
	}

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

	if (index >= repertoire.get_index())
	{
		std::cout << "Index non identifié" << std::endl;
		return;
	}

	print_contact(pb[index]);
}
