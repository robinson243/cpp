/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 00:48:05 by romukena          #+#    #+#             */
/*   Updated: 2025/12/29 14:19:23 by romukena         ###   ########.fr       */
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
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			int count = pb.get_index() % 8;
			repertoire[count] = Add();
			pb.increment();
		}
		if (input == "SEARCH")
		{
			std::string num;
			std::cout << "Ecris un index > ";
			std::getline(std::cin, num);
			Search(pb, num);
		}
		if (input == "EXIT")
			break;
	}
}
