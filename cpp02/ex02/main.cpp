/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:49:23 by romukena          #+#    #+#             */
/*   Updated: 2026/01/17 16:33:45 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	return 0;
}


// int main() {
//     Fixed a(5.05f);
//     Fixed b(2);

//     std::cout << "a = " << a << "\n";
//     std::cout << "b = " << b << "\n\n";

//     // --- Arithmetic operators ---
//     Fixed c = a + b;
//     Fixed d = a - b;
//     Fixed e = a * b;
//     Fixed f = a / b;

//     std::cout << "a + b = " << c << "\n";
//     std::cout << "a - b = " << d << "\n";
//     std::cout << "a * b = " << e << "\n";
//     std::cout << "a / b = " << f << "\n\n";

//     // --- Comparison operators ---
//     std::cout << "a > b ? " << (a > b) << "\n";
//     std::cout << "a < b ? " << (a < b) << "\n";
//     std::cout << "a >= b ? " << (a >= b) << "\n";
//     std::cout << "a <= b ? " << (a <= b) << "\n";
//     std::cout << "a == b ? " << (a == b) << "\n";
//     std::cout << "a != b ? " << (a != b) << "\n\n";

//     // --- Increment / Decrement (if implemented) ---
//     Fixed g = a;
//     std::cout << "g = " << g << "\n";
//     std::cout << "++g = " << ++g << "\n";
//     std::cout << "g++ = " << g++ << "\n";
//     std::cout << "g = " << g << "\n";
//     std::cout << "--g = " << --g << "\n";
//     std::cout << "g-- = " << g-- << "\n";
//     std::cout << "g = " << g << "\n\n";

//     // --- Min / Max (if implemented as static) ---
//     std::cout << "Min(a, b) = " << Fixed::min(a, b) << "\n";
//     std::cout << "Max(a, b) = " << Fixed::max(a, b) << "\n";

//     return 0;
// }

