/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 00:25:47 by romukena          #+#    #+#             */
/*   Updated: 2026/01/02 03:33:14 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
	Weapon &weapon_type;
	std::string name;

public:
	HumanA(std::string newName, Weapon &newWeapon);
	~HumanA();
	void attack(void) const;
};

#endif