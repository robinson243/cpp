/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 23:26:31 by romukena          #+#    #+#             */
/*   Updated: 2026/03/11 15:02:03 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.tpp"
#include "limits"

Array::Array()
{
	return new T[];
}

Array~Array()
{};

Array::Array(unsigned int n)
{
	if (n <= 0)
		return ;
	if (n < std::numeric_limits<unsigned int>::min() || n > std::numeric_limits<unsigned int>::min())
	{
		std::cerr << "Number off range" << std::endl; 
	}
	return new T[n];
}

Array::Array(const T &other)
{
}

Array & Array::operator=(const T &other)
{
	if (this != &other)
	{
		;
	}
	return *this;
}