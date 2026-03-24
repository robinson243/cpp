/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:32:57 by romukena          #+#    #+#             */
/*   Updated: 2026/03/24 16:25:55 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	BitcoinExchange map;
	if (ac == 2) {
		if (data_add("data.csv", map) == -1 || input_add(av[1], map) == -1)
		{
			std::cerr << "Error: could not open file" << std::endl;
			return 1;
		}
		validate_value(map);
		validate_date(map);
		findLowerBound(map);
		// for (std::list<std::pair<std::string, std::string> >::iterator it =
		// 		 map.input_data.begin();
		// 	 it != map.input_data.end();
		// 	 ++it)
		// {
		// 	std::cout << it->first << " => " << it->second << std::endl;
		// }
	} else
		std::cerr << "Error: could not open file" << std::endl;
	return 0;
}