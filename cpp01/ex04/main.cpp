/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:03:02 by romukena          #+#    #+#             */
/*   Updated: 2026/01/15 18:20:24 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int main(int ac, char **av) {
	std::string buffer;
	if (ac != 4) {
		std::cerr << "Error ! Must be 3 arguments" << std::endl;
		return (1);
	}
	std::ifstream readfile(av[1]);
	if (!readfile.is_open()) {
		std::cerr << "Error: cannot open file " << av[1] << std::endl;
		return 1;
	}
	std::string castArg = av[1];
	std::string filename = castArg.append(".replace");
	std::ofstream newfile(filename.c_str());
	if (!newfile.is_open()) {
		std::cerr << "Error: cannot create output file " << filename
				  << std::endl;
		return 1;
	}
	std::string search = av[2];
	if (search.empty()) {
		std::cerr << "Error: search string cannot be empty" << std::endl;
		return 1;
	}
	std::string replaceStr = av[3];
	if (replaceStr.empty()) {
		std::cerr << "Warning: replace string is empty, matches will be deleted"
				  << std::endl;
	}
	std::string content;
	bool first_line = true;
	while (std::getline(readfile, buffer)) {
		size_t pos = 0;
		while ((pos = buffer.find(search, pos)) != std::string::npos) {
			buffer.erase(pos, search.length());
			buffer.insert(pos, replaceStr);
			pos += replaceStr.length();
		}
		if (!first_line) {
			newfile << '\n';
		}
		if (!(newfile << buffer)) {
			std::cerr << "Error writing to file" << std::endl;
			return 1;
		}
		first_line = false;
	}
	readfile.close();
	newfile.close();
}
