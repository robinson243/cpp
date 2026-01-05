/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:03:02 by romukena          #+#    #+#             */
/*   Updated: 2026/01/05 02:20:51 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int main(int ac, char **av)
{
	std::string buffer;
	if (ac != 4)
	{
		std::cerr << "Error ! Must be 3 arguments" << std::endl;
		return (1);
	}
	std::ifstream readfile(av[1]);
	if (!readfile.is_open())
	{
		std::cerr << "Error: cannot open file " << av[1] << std::endl;
		return 1;
	}
	std::string castArg = av[1];
	std::string filename = castArg.append(".replace");
	std::ofstream newfile(filename.c_str());
	std::string search = av[2];
	if (search.empty())
	{
		std::cerr << "Error: search string cannot be empty" << std::endl;
		return 1;
	}
	std::string replaceStr = av[3];
	std::string content;
	while (getline(readfile, buffer))
	{
		content += buffer;
		content += "\n";
		size_t pos = 0;
		while ((pos = buffer.find(search, pos)) != std::string::npos)
		{
			buffer.erase(pos, search.length());
			buffer.insert(pos, replaceStr);
			pos += replaceStr.length();
		}
		newfile << buffer << std::endl;
	}
	readfile.close();
}
