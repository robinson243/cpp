/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:18:40 by romukena          #+#    #+#             */
/*   Updated: 2026/01/21 01:05:54 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.hpp"
#include "dog.hpp"

int main()
{
    std::cout << "=== Test 1: Tableau de 4 Animal (subject requis) ===\n";
    const Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Dog();
    animals[2] = new Cat();
    animals[3] = new Cat();
    
    for (int i = 0; i < 4; i++)
        delete animals[i];

    std::cout << "\n=== Test 2: Constructeur de copie Dog ===\n";
    Dog originalDog;
    Dog copyDog(originalDog);
    
    std::cout << "\n=== Test 3: Constructeur de copie Cat ===\n";
    Cat originalCat;
    Cat copyCat(originalCat);

    std::cout << "\n=== Test 4: Operateur assignation Dog ===\n";
    Dog dog1;
    Dog dog2;
    dog2 = dog1;

    std::cout << "\n=== Test 5: Operateur assignation Cat ===\n";
    Cat cat1;
    Cat cat2;
    cat2 = cat1;

    std::cout << "\n=== Test 6: Deep copy avec scope (crucial) ===\n";
    Dog* dogPtr = new Dog();
    {
        Dog tempDog(*dogPtr);
        std::cout << "Fin du scope, tempDog va etre detruit\n";
    }
    std::cout << "dogPtr existe toujours\n";
    delete dogPtr;

    std::cout << "\n=== Test 7: Auto-assignation ===\n";
    Dog selfDog;
    selfDog = selfDog;

    std::cout << "\n=== Fin des tests ===\n";
    return 0;
}
