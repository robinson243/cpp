/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 00:40:11 by romukena          #+#    #+#             */
/*   Updated: 2026/03/31 00:36:36 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe p;
	if (ac == 2)
	{
		p.initVec(av[1]);
		std::vector<int> vec = p.getVec();
		p.sortVec(vec);
		std::vector<int> result = p.sortVec(vec);
		for (size_t i = 0; i < result.size(); i++)
			std::cout << result[i] << " ";
		std::cout << std::endl;
	}
	return 1;
}