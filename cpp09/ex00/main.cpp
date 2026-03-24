/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:32:57 by romukena          #+#    #+#             */
/*   Updated: 2026/03/24 02:33:36 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitcoinExchange map;
	if (ac == 2)
	{
		data_add("data.csv", map);
		input_add(av[1], map);
		validate_value(map);
		for (std::list<std::pair<std::string, std::string> >::iterator it =
				 map.input_data.begin();
			 it != map.input_data.end();
			 ++it)
		{
			std::cout << it->first << " => " << it->second << std::endl;
		}
	}
	return 0;
}