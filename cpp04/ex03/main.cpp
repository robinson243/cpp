/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:44:15 by romukena          #+#    #+#             */
/*   Updated: 2026/01/24 12:00:01 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

// int main() {
// 	IMateriaSource *src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter *me = new Character("me");
// 	AMateria *tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	ICharacter *bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	delete bob;
// 	delete me;
// 	delete src;
// 	return 0;
// }

int main()
{
    std::cout << "=== Test 1: Basic functionality ===" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    std::cout << "\n=== Test 2: MateriaSource full (5 learns) ===" <<
    std::endl; src->learnMateria(new Ice()); src->learnMateria(new Cure());
    AMateria* rejected = new Ice();
    src->learnMateria(rejected); // 5th, ignored
    delete rejected; // Delete manually since not learned

    std::cout << "\n=== Test 3: Unknown type ===" << std::endl;
    tmp = src->createMateria("fire");
    if (tmp == NULL)
        std::cout << "fire type unknown (correct)" << std::endl;

    std::cout << "\n=== Test 4: Character equip full inventory ===" <<
    std::endl; tmp = src->createMateria("ice"); me->equip(tmp); tmp =
    src->createMateria("cure"); me->equip(tmp);

    std::cout << "\n=== Test 5: Attempt equip when full ===" << std::endl;
    ICharacter* full = new Character("full");
    full->equip(src->createMateria("ice"));
    full->equip(src->createMateria("cure"));
    full->equip(src->createMateria("ice"));
    full->equip(src->createMateria("cure"));

    tmp = src->createMateria("ice");
    full->equip(tmp); // Fails, inventory full
    delete tmp;

    std::cout << "\n=== Test 6: Invalid indices ===" << std::endl;
    me->use(-1, *bob);
    me->use(10, *bob);
    me->unequip(-1);
    me->unequip(10);

    std::cout << "\n=== Test 7: Unequip and manual delete ===" << std::endl;
    ICharacter* test = new Character("test");
    AMateria* floor_item = src->createMateria("cure");
    test->equip(floor_item);
    test->use(0, *bob);
    test->unequip(0);
    delete floor_item;

    std::cout << "\n=== Test 8: Deep copy Character ===" << std::endl;
    ICharacter* original = new Character("original");
    original->equip(src->createMateria("ice"));
    original->equip(src->createMateria("cure"));
    original->use(0, *bob);
    original->use(1, *bob);

    Character copy(*(Character*)original);
    delete original;

    copy.use(0, *bob);
    copy.use(1, *bob);

    std::cout << "\n=== Test 9: Deep copy MateriaSource ===" << std::endl;
    MateriaSource* src2 = new MateriaSource();
    src2->learnMateria(new Ice());
    src2->learnMateria(new Cure());

    MateriaSource srcCopy(*src2);
    delete src2;

    tmp = srcCopy.createMateria("ice");
    if (tmp)
    {
        std::cout << "MateriaSource deep copy works!" << std::endl;
        delete tmp;
    }
    tmp = srcCopy.createMateria("cure");
    if (tmp)
    {
        std::cout << "MateriaSource deep copy works!" << std::endl;
        delete tmp;
    }

    std::cout << "\n=== Cleanup ===" << std::endl;
    delete test;
    delete full;
    delete bob;
    delete me;
    delete src;

    std::cout << "\n=== All tests completed successfully ===" << std::endl;
    return 0;
}
