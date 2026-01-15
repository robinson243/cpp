/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 18:32:36 by romukena          #+#    #+#             */
/*   Updated: 2026/01/15 17:41:42 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int n = 6;
	std::string name = "charlie";
	Zombie *Horde = zombieHorde(n, name);
	for (int i = 0; i < n; i++)
	{
		std::cout << "Index :" << i << std::endl;
		Horde[i].announce();
	}
	delete[] Horde;
}