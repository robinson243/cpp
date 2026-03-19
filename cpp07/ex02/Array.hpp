/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 23:21:51 by romukena          #+#    #+#             */
/*   Updated: 2026/03/19 13:52:48 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <limits>
#include <stdexcept>

template <typename T> class Array {
  private:
	T *_value;
	unsigned int _size;

  public:
	Array();
	~Array();
	Array(unsigned int n);
	Array(const Array &other);
	Array &operator=(const Array<T> &other);
	class OutOfRange : public std::exception {};
	T &operator[](unsigned int index) const;
	unsigned int size() const;
};

#include "Array.tpp"

#endif