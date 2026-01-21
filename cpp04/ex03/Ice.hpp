/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:23:32 by romukena          #+#    #+#             */
/*   Updated: 2026/01/22 20:25:05 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Ice : public AMateria {
  public:
	Ice();
	~Ice();
	Ice &operator=(const Ice &other);
	Ice(const Ice &other);
	virtual Ice *clone() const;
	virtual void use(ICharacter &target);
};

#endif