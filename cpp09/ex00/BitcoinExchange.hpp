/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 22:50:48 by romukena          #+#    #+#             */
/*   Updated: 2026/03/24 14:39:55 by romukena         ###   ########.fr       */
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
  public:
	std::list<std::pair<std::string, std::string> > input_data;
	std::map<std::string, std::string> other_data;
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
};

void data_add(std::string file, BitcoinExchange &map);
void input_add(std::string file, BitcoinExchange &map);
void validate_value(BitcoinExchange &map);
bool isLeapYear(int year);
bool isValidDate(int year, int month, int day);
void validate_date(BitcoinExchange &map);
void findLowerBound(BitcoinExchange &map);