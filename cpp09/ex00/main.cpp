/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:32:57 by romukena          #+#    #+#             */
/*   Updated: 2026/04/04 01:47:14 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	BitcoinExchange map;
	if (ac == 2) {
		if (map.data_add("data.csv") == -1 || map.input_add(av[1]) == -1)
		{
			std::cerr << "Error: could not open file" << std::endl;
			return 1;
		}
		map.validate_value();
		map.validate_date();
		map.findLowerBound();
	} else
		std::cerr << "Error: could not open file" << std::endl;
	return 0;
}