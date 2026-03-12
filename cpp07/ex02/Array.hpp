/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 23:21:51 by romukena          #+#    #+#             */
/*   Updated: 2026/03/12 02:10:00 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP
#include <iostream>
#include "limits"
#include <stdexcept>

template <typename T>
class Array
{
private:
	T *_value;
	unsigned int _size;

public:
	Array()
	{
		_size = 0;
		_value = new T[_size];
	};
	~Array() { delete[] _value; };
	Array(unsigned int n)
	{
		_size = n;
		_value = new T[n];
	};
	Array(const Array &other)
	{
		_size = other.size();
		_value = new T[_size];
		for (unsigned int i = 0; i < other.size(); i++)
			_value[i] = other[i];
	};
	Array &operator=(const Array &other)
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
	class OutOfRange : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Invalid index : out of range";
		}
	};
	T &operator[](unsigned int index) const
	{
		if (index >= this->size())
		{
			throw OutOfRange();
		}

		return this->_value[index];
	};
	unsigned int size() const
	{
		return _size;
	};
};

#endif