/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:36:51 by romukena          #+#    #+#             */
/*   Updated: 2026/03/10 18:36:20 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename T>
void iter(T *tab, const int size, void (*f)(T&)) {
	if (size <= 0)
		return;
	for (int i = 0; i < size; i++)
		f(tab[i]);
};

#endif