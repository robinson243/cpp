/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:49:12 by romukena          #+#    #+#             */
/*   Updated: 2026/03/21 14:58:01 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	std::vector<int> vec;

	vec.push_back(5);
	vec.push_back(7);
	vec.push_back(1);
	vec.push_back(54);
	vec.push_back(18);

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 54);
		std::cout << *it << std::endl;
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}