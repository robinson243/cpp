/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:36:51 by romukena          #+#    #+#             */
/*   Updated: 2026/03/20 19:21:04 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename T>
void iter(T *tab, const size_t size, void (*f)(T &))
{
	if (!tab || !f || size <= 0)
		return;
	for (size_t i = 0; i < size; i++)
		f(tab[i]);
};

template <typename T>
void iter(const T *tab, const size_t size, void (*f)(const T &))
{
	if (!tab || !f || size <= 0)
		return;
	for (size_t i = 0; i < size; ++i)
		f(tab[i]);
}

#endif