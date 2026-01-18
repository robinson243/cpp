/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:45:02 by romukena          #+#    #+#             */
/*   Updated: 2026/01/18 23:46:10 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	std::cout << "=== Création basique ===" << std::endl;
	FragTrap a("Fraggy");
	a.attack("enemy1");
	a.highFivesGuys();

	std::cout << std::endl;
	std::cout << "=== Constructeur par défaut ===" << std::endl;
	FragTrap b;
	b.highFivesGuys();

	std::cout << std::endl;
	std::cout << "=== Constructeur de copie ===" << std::endl;
	FragTrap c(a);
	c.attack("enemy2");
	c.highFivesGuys();

	std::cout << std::endl;
	std::cout << "=== Opérateur d'assignation ===" << std::endl;
	b = a;
	b.attack("enemy3");
	b.highFivesGuys();

	std::cout << std::endl;
	std::cout << "=== Polymorphisme (base) ===" << std::endl;
	ClapTrap *ptr = new FragTrap("PolyFrag");
	ptr->attack("enemy4");
	delete ptr;

	std::cout << std::endl;
	std::cout << "=== Objet temporaire ===" << std::endl;
	FragTrap("TempFrag").highFivesGuys();

	std::cout << std::endl;
	std::cout << "=== Fin du programme ===" << std::endl;
	return 0;
}