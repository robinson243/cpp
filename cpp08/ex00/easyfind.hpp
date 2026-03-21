/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 18:36:21 by romukena          #+#    #+#             */
/*   Updated: 2026/03/21 14:49:42 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T> typename T::iterator easyfind(T &container, int n) {
	typename T::iterator it = find(container.begin(), container.end(), n);
	if (it == container.end()) {
		throw std::invalid_argument("Value not found");
	} else
		return it;
}

#endif