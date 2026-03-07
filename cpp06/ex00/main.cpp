/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:42:30 by romukena          #+#    #+#             */
/*   Updated: 2026/03/07 01:41:30 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		ScalarConverter object(av[1]);
		
		std::cout << object.isFloat() << std::endl;
	}
	return 1;
}