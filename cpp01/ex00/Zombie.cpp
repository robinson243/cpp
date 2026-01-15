/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 01:27:13 by romukena          #+#    #+#             */
/*   Updated: 2026/01/15 17:40:52 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
}

Zombie::Zombie(std::string _name) {
	name = _name;
}

Zombie::~Zombie() {
	std::cout << name << " is deleted" << std::endl;
}

void Zombie::announce(void) {
	if (!name.empty())
		std::cout << name << ":" << " BraiiiiiiinnnzzzZ..." << std::endl;
}