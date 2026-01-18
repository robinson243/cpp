/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 14:08:18 by romukena          #+#    #+#             */
/*   Updated: 2026/01/18 14:35:52 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	// 1. Création par défaut
	ScavTrap a;

	// 2. Création avec un nom
	ScavTrap b("RoboGuard");

	// 3. Appel de l'attaque
	a.attack("un ennemi"); // message spécifique à ScavTrap si redéfini
	b.attack("un autre ennemi");

	// 4. Capacité spéciale
	a.guardGate();
	b.guardGate();

	// 5. Copie
	ScavTrap c(b); // constructeur de copie
	c.guardGate();

	// 6. Opérateur=
	a = c;
	a.guardGate();

	// 7. Destruction automatique à la fin du main
	// Les messages de destruction doivent montrer :
	// c puis b puis a (ou dans l’ordre inverse de création)

	return 0;
}
