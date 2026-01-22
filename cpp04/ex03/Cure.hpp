/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:42:39 by romukena          #+#    #+#             */
/*   Updated: 2026/01/22 14:10:47 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Cure : public AMateria {
  public:
	Cure();
	~Cure();
	Cure &operator=(const Cure &other);
	Cure(const Cure &other);
	virtual Cure *clone() const;
	virtual void use(ICharacter& target);
	
};

#endif