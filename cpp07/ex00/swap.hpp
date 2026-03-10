/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:01:55 by romukena          #+#    #+#             */
/*   Updated: 2026/03/10 17:28:19 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_HPP
#define SWAP_HPP
#include <iostream>

template <typename T> void swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

#endif