/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 00:40:11 by romukena          #+#    #+#             */
/*   Updated: 2026/03/30 01:35:43 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe p;
	if (ac == 2)
	{
		p.initVec(av[1]);
		std::vector<std::pair<int, int> > vecPair = p.makePair();
		p.doGreatPair(vecPair);
		for (size_t i = 0; i < vecPair.size(); i++)
		{
			std::cout << "First: " << vecPair[i].first << ", Second: "
					  << vecPair[i].second << std::endl;
		}
	}
	return 1;
}