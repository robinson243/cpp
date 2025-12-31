/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 23:05:30 by romukena          #+#    #+#             */
/*   Updated: 2025/12/31 07:29:19 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name)
{
	if (name.empty())
	{
		std::cerr << "There is no name here" << std::endl;
		return;
	}
	Zombie perso = Zombie(name);
	perso.announce();
}