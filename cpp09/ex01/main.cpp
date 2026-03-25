/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:07:25 by romukena          #+#    #+#             */
/*   Updated: 2026/03/25 18:07:54 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        RPN calculator(av[1]);
        calculator.showElement();
        std::cout << calculator.isNumber() << std::endl;
    }
    else
        std::cerr << "Error" << std::endl;
    return 1;
}