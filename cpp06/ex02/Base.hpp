/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:32:51 by romukena          #+#    #+#             */
/*   Updated: 2026/03/10 15:14:22 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <cstdlib>
#include <stdio.h>
#include <iostream>

class Base {
  public:
	virtual ~Base();
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif