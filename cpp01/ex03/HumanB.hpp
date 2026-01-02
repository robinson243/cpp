/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 02:17:11 by romukena          #+#    #+#             */
/*   Updated: 2026/01/01 20:02:32 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
	Weapon weapon_type;
	std::string name;
public:
	HumanB();
	~HumanB();
	HumanB(std::string _name);
	void attack(void);
	void setWeapon(Weapon weapon);
};




#endif