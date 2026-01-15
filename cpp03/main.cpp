/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 00:34:40 by romukena          #+#    #+#             */
/*   Updated: 2026/01/15 01:18:41 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a("Alpha");
    ClapTrap b("Bravo");

    a.attack("Bravo");
    b.takeDamage(0);

    b.beRepaired(5);

    // vider l'énergie de a
    a.attack("Bravo");
    a.attack("Bravo");
    a.attack("Bravo");
    a.attack("Bravo");
    a.attack("Bravo");
    a.attack("Bravo");
    a.attack("Bravo");
    a.attack("Bravo");
    a.attack("Bravo");
    a.attack("Bravo");

    // tentative d'action sans énergie
    a.attack("Bravo");
    a.beRepaired(3);

    // mettre b à 0 HP
    b.takeDamage(100);

    // tentative d'action sans HP
    b.attack("Alpha");
    b.beRepaired(10);

    return 0;
}
