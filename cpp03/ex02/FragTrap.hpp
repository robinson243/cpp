/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:18:09 by romukena          #+#    #+#             */
/*   Updated: 2026/01/18 23:40:57 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap
{
private:

public:
	FragTrap(const std::string _Nname);
	FragTrap();
	~FragTrap();
	FragTrap &operator=(const FragTrap &other);
	FragTrap(const FragTrap &other);
	void attack(const std::string &target);
	void highFivesGuys(void);
};

#endif