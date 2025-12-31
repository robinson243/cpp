/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 23:05:34 by romukena          #+#    #+#             */
/*   Updated: 2025/12/31 18:48:43 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
private:
	std::string name;

public:
	Zombie();
	~Zombie();
	Zombie(std::string _name);
	void announce(void);
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif