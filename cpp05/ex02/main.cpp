/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:40:05 by romukena          #+#    #+#             */
/*   Updated: 2026/02/28 14:43:26 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>

int main() {
	srand(time(NULL));
	/*Shrubbery*/
	// std::cout << "=== SHRUBBERYCREATIONFORM TEST ===\n\n";

	// Bureaucrat gardener("Gardener", 130); // execGrade=137 → OK
	// std::cout << "Gardener: " << gardener << "\n";

	// // 1. Créer form
	// ShrubberyCreationForm tree("jardin");
	// std::cout << "Tree form: " << tree << "\n\n";

	// // 2. Signe (grade 130 <= signGrade 145)
	// tree.beSigned(gardener);
	// std::cout << "Après signature: " << tree << "\n\n";

	// // 3. Execute succès
	// std::cout << "EXECUTE SUCCES:\n";
	// tree.execute(gardener);
	// std::cout << "✓ Fichier jardin_shrubbery créé !\n\n";

	// // 4. Grade trop bas
	// Bureaucrat noob("Noob", 140); // 140 > 137 → FAIL
	// std::cout << "Noob grade: " << noob.getGrade() << "\n";
	// try
	// {
	//     tree.execute(noob);
	// }
	// catch (std::exception &e)
	// {
	//     std::cout << "✓ Noob refusé: " << e.what() << "\n";
	// }

	// // 5. Vérif fichier
	// std::ifstream file("jardin_shrubbery");
	// std::cout << "✓ Fichier existe: " << (file.good() ? "OUI" : "NON") <<
	// "\n";

	/*Robotomy*/

	// Bureaucrat boss("Boss", 1);
	// Bureaucrat gardener("Gardener", 130);

	// RobotomyRequestForm robot("Target42");

	// std::cout << "=== ROBOTOMY TEST ===\n";
	// std::cout << boss << robot << "\n";

	// // 1. Sign
	// robot.beSigned(boss);
	// std::cout << "\nAprès signature: " << robot << "\n";

	// // 2. Execute Boss (grade 1 < 45)
	// try
	// {
	//     robot.execute(boss);
	//     std::cout << "✓ Boss execute OK\n";
	// }
	// catch (std::exception &e)
	// {
	//     std::cout << "✗ Boss erreur: " << e.what() << "\n";
	// }

	// // 3. Gardener échoue (130 > 45)
	// try
	// {
	//     robot.execute(gardener);
	// }
	// catch (std::exception &e)
	// {
	//     std::cout << "✓ Gardener refusé: " << e.what() << "\n";
	// }

	/*Presidential*/

	// Bureaucrat president("POTUS", 1);
	// Bureaucrat secretary("Secretary", 24);

	// PresidentialPardonForm pardon("Alice");

	// std::cout << "=== PRESIDENTIAL TEST ===\n";
	// std::cout << president << pardon << "\n";

	// // 1. Sign (25 max)
	// pardon.beSigned(president);
	// std::cout << "\nAprès signature: " << pardon << "\n";

	// // 2. Execute POTUS (1 < 25)
	// try {
	// 	pardon.execute(president);
	// 	std::cout << "✓ POTUS pardon OK\n";
	// } catch (std::exception &e) {
	// 	std::cout << "✗ POTUS erreur: " << e.what() << "\n";
	// }

	// // 3. Secretary échoue (24 == 25? → NO)
	// try {
	// 	pardon.execute(secretary);
	// } catch (std::exception &e) {
	// 	std::cout << "✓ Secretary refusé: " << e.what() << "\n";
	// }

    /*ExecuteForm*/
	Bureaucrat boss("Boss", 1);

	ShrubberyCreationForm shrub("jardin");
	RobotomyRequestForm robo("Target");
	PresidentialPardonForm pardon("Alice");

	shrub.beSigned(boss);
	robo.beSigned(boss);
	pardon.beSigned(boss);

	std::cout << "=== TEST executeForm ===\n";
	boss.executeForm(shrub);
	boss.executeForm(robo);
	boss.executeForm(pardon);

	return 0;
}