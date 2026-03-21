/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:48:05 by romukena          #+#    #+#             */
/*   Updated: 2026/03/21 13:02:20 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void addFive(int &x) {
	x += 5;
}
void printInt(int const &x) {
	std::cout << x << std::endl;
}

int main() {
	int tab[] = { 4, 85, 12, 22, 32 };
	size_t size = 5;

	iter(tab, size, addFive);  // version non-const
	iter(tab, size, printInt); // version const (subject-safe)

	return 0;
}