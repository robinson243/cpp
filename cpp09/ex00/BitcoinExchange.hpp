/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 22:50:48 by romukena          #+#    #+#             */
/*   Updated: 2026/03/23 17:45:59 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
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

void data_add(std::string file, BitcoinExchange map);
void input_add(std::string file, BitcoinExchange map);
void validate_value(BitcoinExchange map);