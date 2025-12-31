/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 01:27:13 by romukena          #+#    #+#             */
/*   Updated: 2025/12/31 01:46:54 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::~Zombie()
{
	std::cout << name << " is deleted" << std::endl;
}


void Zombie::announce(void)
{
	std::cout << getName() << ":" << " BraiiiiiiinnnzzzZ..." << std::endl; 
}