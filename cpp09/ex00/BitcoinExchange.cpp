/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 11:46:46 by romukena          #+#    #+#             */
/*   Updated: 2026/03/24 02:37:17 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};
BitcoinExchange::~BitcoinExchange() {};
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->input_data = other.input_data;
		this->other_data = other.other_data;
	}
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->input_data = other.input_data;
		this->other_data = other.other_data;
	}
	return *this;
}

void data_add(std::string file, BitcoinExchange &map)
{
	std::ifstream myFile(file.c_str());
	std::string line;
	std::string content;
	getline(myFile, line);
	while (getline(myFile, line))
	{
		content += line;
		content += '\n';
		map.other_data.insert(std::pair<std::string, std::string>(
			line.substr(0, 10), line.substr(11, line.length())));
	}
	myFile.close();
}

void input_add(std::string file, BitcoinExchange &map)
{
	std::ifstream myFile(file.c_str());
	std::string line;
	std::string content;
	getline(myFile, line);
	while (getline(myFile, line))
	{
		content += line;
		content += '\n';
		std::string tmp;
		if (line[10] == '\0')
			tmp = "";
		else
			tmp = line.substr(13, line.length());
		map.input_data.push_back(
			std::pair<std::string, std::string>(line.substr(0, 10), tmp));
	}
	// for (std::list<std::pair<std::string, std::string> >::iterator it =
	// 		 map.input_data.begin();
	// 	 it != map.input_data.end();
	// 	 ++it) {
	// 	std::cout << it->first << " => " << it->second << std::endl;
	// }
	myFile.close();
}

void validate_value(BitcoinExchange &map)
{
	std::list<std::pair<std::string, std::string> > &m = map.input_data;
	for (std::list<std::pair<std::string, std::string> >::iterator it =
			 m.begin();
		 it != m.end();
		 ++it)
	{
		double f_number = atof(it->second.c_str());
		if (it->second == "")
			it->second = "Error: bad input => " + it->first;
		else if (f_number < 0)
			it->second = "Error: not a positive number.";
		else if (f_number > 1000)
			it->second = "Error: too large a number.";
	}
}