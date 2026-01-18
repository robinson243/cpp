/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 14:08:18 by romukena          #+#    #+#             */
/*   Updated: 2026/01/18 15:01:13 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    std::cout << "=== Création d'objets ===" << std::endl;

    ScavTrap a;                         // default constructor
    ScavTrap b("RoboGuard");            // param constructor
    ScavTrap c(b);                       // copy constructor
    ScavTrap d("TempBot");              
    ScavTrap e;                         

    std::cout << "\n=== Tests d'attaque ===" << std::endl;
    a.attack("enemy1");                  // default name
    b.attack("enemy2");                  // named
    c.attack("enemy3");                  // copy of b
    d.attack("enemy4");                  // named
    e.attack("enemy5");                  // default

    std::cout << "\n=== Tests de guardGate ===" << std::endl;
    a.guardGate();                       // no name
    b.guardGate();                       // named
    c.guardGate();                       // copy
    d.guardGate();                       // named
    e.guardGate();                       // no name

    std::cout << "\n=== Tests d'opérateur= ===" << std::endl;
    a = b;                               // assign named to default
    a.guardGate();                       // doit maintenant afficher b's name

    e = c;                               // assign copy to default
    e.guardGate();                       // doit afficher c's name

    std::cout << "\n=== Création et destruction de temporaires ===" << std::endl;
    ScavTrap("Tempory").guardGate();     // temporary object, destruction immédiate

    std::cout << "\n=== Fin du programme ===" << std::endl;
    return 0;
}
