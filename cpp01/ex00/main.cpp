/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 01:30:45 by romukena          #+#    #+#             */
/*   Updated: 2025/12/31 01:45:55 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	// tester la création dynamique
	Zombie* z = newZombie("TestZombie");
	z->announce();

	// tester la création automatique
	randomChump("StackZombie");
	delete z;
	return 0;
}
