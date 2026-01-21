/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:26:34 by romukena          #+#    #+#             */
/*   Updated: 2026/01/21 17:34:16 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP


#include "ICharacter.hpp"
#include <iostream>

class AMateria {
  protected:
  public:
	AMateria();
	~AMateria();
	AMateria &operator=(const AMateria &other);
	AMateria(const AMateria &other);
	std::string const &getType() const;
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};


#endif