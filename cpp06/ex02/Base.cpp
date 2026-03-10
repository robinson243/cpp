/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:51:03 by romukena          #+#    #+#             */
/*   Updated: 2026/03/10 15:53:46 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdio.h>

Base::~Base() {
}

Base *generate(void) {
	switch (rand() % 3) {
	case 0:
		return new A();
	case 1:
		return new B();
	case 2:
		return new C();
	}
	return NULL;
}

void identify(Base *p) {
	if (dynamic_cast<A *>(p))
		std::cout << "L'objet est A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "L'objet est B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "L'objet est C" << std::endl;
}

void identify(Base &p) {
	if (dynamic_cast<A *>(&p))
		std::cout << "L'objet est A" << std::endl;
	else if (dynamic_cast<B *>(&p))
		std::cout << "L'objet est B" << std::endl;
	else if (dynamic_cast<C *>(&p))
		std::cout << "L'objet est C" << std::endl;
}