/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 12:08:23 by romukena          #+#    #+#             */
/*   Updated: 2026/01/12 13:45:51 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

std::string read_field(const std::string &prompt, bool allow_spaces)
{
    std::string input;
    size_t i;

    while (1)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, input))
            std::exit(0);

        if (input.empty())
            continue;

        i = 0;
        while (i < input.size() &&
               std::isspace(static_cast<unsigned char>(input[i])))
            i++;

        if (i == input.size())
            continue;

        if (!allow_spaces)
        {
            i = 0;
            while (i < input.size())
            {
                if (std::isspace(static_cast<unsigned char>(input[i])))
                    break;
                i++;
            }
            if (i != input.size())
                continue;
        }

        // 🔧 TRIM ICI
        size_t start = 0;
        size_t end = input.size();

        while (start < input.size() &&
               std::isspace(static_cast<unsigned char>(input[start])))
            start++;

        while (end > start &&
               std::isspace(static_cast<unsigned char>(input[end - 1])))
            end--;

        input = input.substr(start, end - start);

        return input;
    }
}


Contact Add()
{
    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string number;
    std::string secret;

    firstname = read_field("Ecris le champ firstname : ", true);
    lastname  = read_field("Ecris le champ lastname : ", true);
    nickname  = read_field("Ecris le champ nickname : ", true);
    number    = read_field("Ecris le champ number sans espace : ", false);
    secret    = read_field("Ecris le champ darkest secret : ", true);

    return Contact(firstname, lastname, nickname, number, secret);
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
