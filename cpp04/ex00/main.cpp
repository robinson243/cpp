/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:18:40 by romukena          #+#    #+#             */
/*   Updated: 2026/01/24 11:36:06 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.hpp"
#include "dog.hpp"
#include "wronganimal.hpp"
#include "wrongcat.hpp"
#include <iostream>

int main() {
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	// const WrongAnimal *k = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound();	   // chat
	j->makeSound();	   // chien
	meta->makeSound(); // animal
	// k->makeSound();

	// 👀 test rapide avec un tableau pour voir le polymorphisme
	const Animal *animals[2] = { new Dog(), new Cat() };
	for (int k = 0; k < 2; k++) {
		std::cout << "Animal #" << k << " type: " << animals[k]->getType()
				  << std::endl;
		animals[k]->makeSound();
	}

	// 🚮 on delete tout pour éviter les leaks
	delete meta;
	delete j;
	delete i;
	for (int k = 0; k < 2; k++)
		delete animals[k];

	return 0;
}
