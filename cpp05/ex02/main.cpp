/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:40:05 by romukena          #+#    #+#             */
/*   Updated: 2026/03/12 17:09:58 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>


int main()
{
    srand(time(NULL));

    Bureaucrat boss("Boss", 1);
    Bureaucrat gardener("Gardener", 130);
    Bureaucrat noob("Noob", 140);
    Bureaucrat secretary("Secretary", 24);

    /* === SHRUBBERY === */
    std::cout << "=== SHRUBBERYCREATIONFORM TEST ===\n\n";
    ShrubberyCreationForm tree("jardin");
    std::cout << "Tree form: " << tree << "\n";
    tree.beSigned(gardener);
    std::cout << "Après signature: " << tree << "\n";
    tree.execute(gardener);
    std::cout << "✓ Fichier jardin_shrubbery créé !\n";
    try { tree.execute(noob); }
    catch (std::exception &e) { std::cout << "✓ Noob refusé: " << e.what() << "\n"; }
    std::ifstream file("jardin_shrubbery");
    std::cout << "✓ Fichier existe: " << (file.good() ? "OUI" : "NON") << "\n\n";

    /* === ROBOTOMY === */
    std::cout << "=== ROBOTOMY TEST ===\n\n";
    RobotomyRequestForm robot("Target42");
    robot.beSigned(boss);
    std::cout << "Après signature: " << robot << "\n";
    try { robot.execute(boss); std::cout << "✓ Boss execute OK\n"; }
    catch (std::exception &e) { std::cout << "✗ Boss erreur: " << e.what() << "\n"; }
    try { robot.execute(gardener); }
    catch (std::exception &e) { std::cout << "✓ Gardener refusé: " << e.what() << "\n"; }

    /* === PRESIDENTIAL === */
    std::cout << "\n=== PRESIDENTIAL TEST ===\n\n";
    PresidentialPardonForm pardon("Alice");
    pardon.beSigned(boss);
    std::cout << "Après signature: " << pardon << "\n";
    try { pardon.execute(boss); std::cout << "✓ POTUS pardon OK\n"; }
    catch (std::exception &e) { std::cout << "✗ POTUS erreur: " << e.what() << "\n"; }
    try { pardon.execute(secretary); }
    catch (std::exception &e) { std::cout << "✓ Secretary refusé: " << e.what() << "\n"; }

    /* === EXECUTEFORM === */
    std::cout << "\n=== TEST executeForm ===\n\n";
    ShrubberyCreationForm shrub("garden");
    RobotomyRequestForm robo("Target");
    PresidentialPardonForm pardon2("Bob");
    shrub.beSigned(boss);
    robo.beSigned(boss);
    pardon2.beSigned(boss);
    boss.executeForm(shrub);
    boss.executeForm(robo);
    boss.executeForm(pardon2);

    /* === NON SIGNÉ === */
    std::cout << "\n=== TEST NON SIGNE ===\n\n";
    ShrubberyCreationForm unsigned_form("forest");
    boss.executeForm(unsigned_form);

    /* === GRADE INSUFFISANT === */
    std::cout << "\n=== TEST GRADE INSUFFISANT ===\n\n";
    ShrubberyCreationForm shrub2("garden2");
    shrub2.beSigned(boss);
    boss.executeForm(shrub2);
    noob.executeForm(shrub2);

    return 0;
}
