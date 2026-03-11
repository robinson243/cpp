/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 23:21:51 by romukena          #+#    #+#             */
/*   Updated: 2026/03/11 14:51:58 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP
#include <iostream>

template <typename T>
// template <class Array>
class Array
{
public:
	Array();
	~Array();
	Array(unsigned int n);
	Array(const T &other);
	Array &operator=(const T &other);
	int size();
};

#endif