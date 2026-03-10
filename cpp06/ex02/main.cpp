/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:01:58 by romukena          #+#    #+#             */
/*   Updated: 2026/03/10 15:54:17 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>

// Prototype de la fonction generate
Base *generate(void);

int main() {
	std::srand(std::time(NULL)); // initialisation du rand
	Base *obj = generate();		 // appeler la fonction
	identify(obj);
	identify(*obj);
	return 0;
}