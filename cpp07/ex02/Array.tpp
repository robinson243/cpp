/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 11:26:57 by romukena          #+#    #+#             */
/*   Updated: 2026/03/20 19:23:49 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _value(NULL), _size(0){};

template <typename T>
Array<T>::~Array()
{
	delete[] _value;
};

template <typename T>
Array<T>::Array(unsigned int n)
{
	_size = n;
	_value = new T[n];
};

template <typename T>
Array<T>::Array(const Array &other)
{
	_size = other.size();
	_value = new T[_size];
	for (unsigned int i = 0; i < other.size(); i++)
		_value[i] = other[i];
};

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		delete[] _value;
		_size = other.size();
		_value = new T[_size];
		for (unsigned int i = 0; i < other.size(); i++)
			_value[i] = other[i];
	}
	return *this;
};

template <typename T>
const char *Array<T>::OutOfRange::what() const throw()
{
	return "Invalid index: out of range";
}

template <typename T>
T const &Array<T>::operator[](unsigned int index) const
{
	if (index >= this->size())
		throw OutOfRange();
	return _value[index];
};

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= this->size())
		throw OutOfRange();
	return _value[index];
};

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
};
