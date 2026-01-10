/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 00:48:05 by romukena          #+#    #+#             */
/*   Updated: 2026/01/10 14:22:35 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "utils.hpp"

int main(void)
{
	Phonebook pb;
	Contact *repertoire = pb.get_repertoire();
	std::string input;

	std::cout << "Bienvenue dans mon répertoire" << std::endl;

	while (1)
	{
		std::cout << "Ecris ADD pour ajouter un contact" << std::endl;
		std::cout << "Ecris SEARCH pour chercher un contact" << std::endl;
		std::cout << "Ecris EXIT pour quitter le programme" << std::endl;
		std::cout << "> ";

		if (!std::getline(std::cin, input))
			break;
		if (input.empty())
			continue;
		if (input == "ADD")
		{
			int count = pb.get_index() % 8;
			repertoire[count] = Add();
			pb.increment();
		}
		else if (input == "SEARCH")
		{
			Search(pb);
		}
		else if (input == "EXIT")
			break;
	}
}
