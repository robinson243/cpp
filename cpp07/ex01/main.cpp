/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:48:05 by romukena          #+#    #+#             */
/*   Updated: 2026/03/10 18:36:57 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void to_upper(int &c) {
	c += 5;
}

int main(void) {
	const int size = 5;
	int tab[] = { 4, 85, 12, 22, 32 };
	iter(tab, size, to_upper);
	for (int i = 0; i < size; i++) {
		std::cout << tab[i] << std::endl;
	}
}