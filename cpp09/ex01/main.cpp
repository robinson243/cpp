/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:07:25 by romukena          #+#    #+#             */
/*   Updated: 2026/03/26 14:02:06 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac == 2) {
		RPN calculator(av[1]);
		if (calculator.isValid()) {
			calculator.showElement();
		}
        // std::cout << isInt(av[1]) << std::endl;
	} else
		std::cerr << "Error" << std::endl;
	return 1;
}