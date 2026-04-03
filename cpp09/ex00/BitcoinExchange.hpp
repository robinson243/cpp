/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 22:50:48 by romukena          #+#    #+#             */
/*   Updated: 2026/04/04 01:45:51 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <string>
#include <cstdlib>
#include <sstream>
#include <string>

class BitcoinExchange {
  private:
	std::list<std::pair<std::string, std::string> > input_data;
	std::map<std::string, std::string> other_data;
  public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	std::list<std::pair<std::string, std::string> >getInputData();
	std::map<std::string, std::string> getOtherData();
	int data_add(std::string file);
	int input_add(std::string file);
	void validate_value();
	bool isLeapYear(int year);
	bool isValidDate(int year, int month, int day);
	void validate_date();
	void findLowerBound();
};
