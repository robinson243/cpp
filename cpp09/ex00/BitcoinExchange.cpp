/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 11:46:46 by romukena          #+#    #+#             */
/*   Updated: 2026/03/25 13:38:33 by romukena         ###   ########.fr       */
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

int data_add(std::string file, BitcoinExchange &map)
{
	std::ifstream myFile(file.c_str());
	if (!myFile.is_open())
		return -1;
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
	return 0;
}

int input_add(std::string file, BitcoinExchange &map)
{
	std::ifstream myFile(file.c_str());
	if (!myFile.is_open())
		return -1;
	std::string line;
	std::string content;
	getline(myFile, line);
	while (getline(myFile, line))
	{
		content += line;
		content += '\n';
		size_t pipe_pos = line.find('|');
		if (pipe_pos == std::string::npos || pipe_pos < 11 || pipe_pos + 2 >= line.length())
		{
			map.input_data.push_back(std::pair<std::string,
				std::string>(line, "Error: bad input => " + line));
			continue;
		}
		std::string date = line.substr(0, 10);
		std::string value = line.substr(pipe_pos + 2, line.length());
		map.input_data.push_back(std::pair<std::string, std::string>(date, value));
	}
	// for (std::list<std::pair<std::string, std::string> >::iterator it =
	// 		 map.input_data.begin();
	// 	 it != map.input_data.end();
	// 	 ++it) {
	// 	std::cout << it->first << " => " << it->second << std::endl;
	// }
	myFile.close();
	return 0;
}

void validate_value(BitcoinExchange &map)
{
	std::list<std::pair<std::string, std::string> > &m = map.input_data;
	for (std::list<std::pair<std::string, std::string> >::iterator it =
			 m.begin();
		 it != m.end();
		 ++it)
	{
		if (it->first.length() < 10)
		{
			it->second = "Error: bad input => " + it->first;
			continue;
		}
		if (it->second.find_first_not_of(" \t") == std::string::npos)
		{
		    it->second = "Error: bad input => " + it->first;
		    continue;
		}
		char *end;
		double f_number = strtod(it->second.c_str(), &end);
		while (*end == ' ')
            end++;
		if (*end != '\0')
		{
		    it->second = "Error: bad input => " + it->first;
		    continue;
		}
		if (it->second == "")
			it->second = "Error: bad input => " + it->first;
		else if (f_number < 0)
			it->second = "Error: not a positive number.";
		else if (f_number > 1000)
			it->second = "Error: too large a number.";
	}
}

bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(int year, int month, int day)
{
	// the 1st element represents the number of days in January,
	// second for Feb and so on, the last element represents days in Dec
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	// Check if year is valid (greater than 0)
	if (year <= 0)
		return false;

	// Check if month is between 1 and 12
	if (month < 1 || month > 12)
		return false;

	// Check for February in case of leap year
	if (month == 2 && isLeapYear(year))
	{
		if (day < 1 || day > 29)
			return false;
	}
	else
	{
		// Check if day is within the range for the given month
		if (day < 1 || day > daysInMonth[month - 1])
			return false;
	}
	// If all conditions are met, the date is valid
	return true;
}

void validate_date(BitcoinExchange &map)
{
	std::list<std::pair<std::string, std::string> > &m = map.input_data;
	for (std::list<std::pair<std::string, std::string> >::iterator it =
			 m.begin();
		 it != m.end();
		 ++it)
	{
		if (it->first.length() < 10)
		{
			it->second = "Error: bad input => " + it->first;
			continue;
		}		
		int year = std::atoi(it->first.substr(0, 4).c_str());
		int month = std::atoi(it->first.substr(5, 2).c_str());
		int day = std::atoi(it->first.substr(8, 2).c_str());
		if (isValidDate(year, month, day) != true)
			it->second = "Error: bad input => " + it->first;
	}
}

void findLowerBound(BitcoinExchange &map)
{
	std::map<std::string, std::string> &m_other = map.other_data;
	std::list<std::pair<std::string, std::string> > &m_input = map.input_data;
	std::map<std::string, std::string>::iterator itOther;

	for (std::list<std::pair<std::string, std::string> >::iterator it =
			 m_input.begin();
		 it != m_input.end();
		 ++it)
	{
		char *endptr;
		double input_val = strtod(it->second.c_str(), &endptr);
		if (*endptr != '\0')
		{
			std::cout << it->second << std::endl;
			continue;
		}
		itOther = m_other.lower_bound(it->first);
		if (itOther == m_other.end())
		{
			--itOther;
		}
		else if (itOther->first != it->first)
		{
			if (itOther != m_other.begin())
				--itOther;
		}
		std::string val = it->second;
		double rate = std::atof(itOther->second.c_str());
		std::map<std::string, std::string>::iterator end = m_other.end();
		--end;
		std::map<std::string, std::string>::iterator first = m_other.begin();
		if (end->first < it->first)
		{
			rate = std::atof(end->second.c_str());
		}
		if (first->first > it->first)
		{
			rate = 0.0;
		}
		double result = input_val * rate;
		std::ostringstream oss;
		oss << result;
		it->second = oss.str();
		if (!(it->second.substr(0, 5) == "Error"))
			std::cout << it->first << " => " << val << " = " << it->second
					  << std::endl;
	}
}
