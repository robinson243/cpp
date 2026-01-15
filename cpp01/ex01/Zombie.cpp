/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 18:28:46 by romukena          #+#    #+#             */
/*   Updated: 2026/01/15 17:40:41 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
}
Zombie::~Zombie() {
}

void Zombie::setName(std::string newName) {
	name = newName;
}

void Zombie::announce(void) {
	if (!name.empty())
		std::cout << name << ":" << " BraiiiiiiinnnzzzZ..." << std::endl;
}