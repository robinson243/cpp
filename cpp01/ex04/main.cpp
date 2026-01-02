/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:03:02 by romukena          #+#    #+#             */
/*   Updated: 2026/01/02 18:37:41 by romukena         ###   ########.fr       */
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
	std::string castArg = av[1];
	std::string filename = castArg.append(".replace");
	std::ofstream newfile(filename);
	while (getline(readfile, buffer, '\0'))
	{
		newfile << buffer;
	}
	readfile.close();
}