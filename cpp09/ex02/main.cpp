/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 00:40:11 by romukena          #+#    #+#             */
/*   Updated: 2026/04/02 01:02:26 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iomanip>
#include <ctime>
#include <sys/time.h>

int main(int ac, char **av)
{
	PmergeMe p;
	if (ac == 2)
	{
		if (!p.initVec(av[1]) || !p.initDeque(av[1]))
		{
			std::cerr << "There is a things other than numbers" << std::endl;
			return 1;
		}
		std::vector<int> veco = p.getVec();
		if (!p.isDuplicate(veco))
		{
			std::cerr << "There is a duplicate numbers" << std::endl;
			return 1;
		}
		
		std::cout << "Before:	";
		for (size_t i = 0; i < p.getVec().size(); i++)
		{
			std::cout << p.getVec()[i] << " ";
		}
		std::cout << "\n";
		std::cout << "After:	";

		std::deque<int> deq = p.getDeque();
		struct timeval beginD;
		gettimeofday(&beginD, NULL);
		std::deque<int> resultDeq = p.sortDeque(deq);
		struct timeval endD;
		gettimeofday(&endD, NULL);
		double millisD = (endD.tv_sec - beginD.tv_sec) * 1000000 + (endD.tv_usec - beginD.tv_usec);
		for (size_t i = 0; i < resultDeq.size(); i++)
		{
			std::cout << resultDeq[i];
			if (i == (resultDeq.size() - 1))
				break;
			std::cout << " ";
		}
		std::cout << "\n";

		std::vector<int> vec = p.getVec();
		struct timeval begin;
		gettimeofday(&begin, NULL);
		std::vector<int> resultVec = p.sortVec(vec);
		struct timeval end;
		gettimeofday(&end, NULL);

		double millis = (end.tv_sec - begin.tv_sec) * 1000000 + (end.tv_usec - begin.tv_usec);
		std::cout << "Time to process a range of	" << vec.size() << " elements with std::vector :	" << std::fixed << std::setprecision(5) <<  millis << " us" << std::endl;

		std::cout << "Time to process a range of	" << deq.size() << " elements with std::deque  :	"<< std::fixed << std::setprecision(5) << millisD << " us" << std::endl;

		// for (size_t i = 0; i < result.size(); i++)
		// 	std::cout << result[i] << " ";
		// std::cout << std::endl;
	}
	return 0;
}
