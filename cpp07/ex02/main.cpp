/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 00:11:34 by romukena          #+#    #+#             */
/*   Updated: 2026/03/12 01:32:31 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    // Constructeur par défaut
    Array<int> empty;

    // Constructeur avec taille
    Array<int> a(5);
    for (unsigned int i = 0; i < a.size(); i++)
        a[i] = i * 10;

    // Copie (deep copy)
    Array<int> b(a);
    b[0] = 999;

    std::cout << "a[0] = " << a[0] << std::endl; // doit rester 0
    std::cout << "b[0] = " << b[0] << std::endl; // doit être 999

    // Test out of bounds
    try {
        a[999] = 0;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test avec un autre type
    Array<std::string> s(3);
    s[0] = "hello";
    std::cout << s[0] << std::endl;

    return 0;
}
