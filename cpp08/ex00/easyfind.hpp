/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 18:36:21 by romukena          #+#    #+#             */
/*   Updated: 2026/03/16 15:28:26 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
	std::vector<int>::iterator it = find(container.begin(), container.end(), n);
	if (it == container.end())
	{
		throw std::invalid_argument("Don't find");
	}
	else
		return it;
}

#endif