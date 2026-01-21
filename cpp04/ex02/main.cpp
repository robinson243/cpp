/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:32:05 by romukena          #+#    #+#             */
/*   Updated: 2026/01/21 15:33:12 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include <iostream>

int main() {
    std::cout << "=== Test 1: Tentative d'instanciation Animal ===" << std::endl;
    // Animal a;  // ❌ Doit être une erreur de compilation si bien abstraite
    // Animal b("generic");  // ❌ Doit être une erreur aussi
    
    std::cout << "=== Test 2: Instanciation classes dérivées ===" << std::endl;
    Dog dog;
    Cat cat;
    
    std::cout << "\n=== Test 3: Polymorphisme avec pointeurs ===" << std::endl;
    Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();
    
    std::cout << "\n=== Test 4: Appel makeSound via polymorphisme ===" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << animals[i]->getType() << ": ";
        animals[i]->makeSound();
    }
    
    std::cout << "\n=== Test 5: Nettoyage ===" << std::endl;
    for (int i = 0; i < 4; i++) {
        delete animals[i];
    }
    
    return 0;
}
