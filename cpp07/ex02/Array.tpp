/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 11:26:57 by romukena          #+#    #+#             */
/*   Updated: 2026/03/21 13:57:51 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T> Array<T>::Array() : _value(NULL), _size(0){};

template <typename T> Array<T>::~Array() {
	delete[] _value;
};

template <typename T> Array<T>::Array(unsigned int n) : _value(NULL), _size(n) {
	if (n == 0)
		return;
	_value = new T[n]();
};

template <typename T> Array<T>::Array(const Array &other) {
	_size = other.size();
	_value = new T[_size];
	for (unsigned int i = 0; i < other.size(); i++)
		_value[i] = other[i];
};

template <typename T> Array<T> &Array<T>::operator=(const Array<T> &other) {
	if (this != &other) {
		Array tmp(other.size());
		for (unsigned int i = 0; i < other.size(); i++)
			tmp._value[i] = other[i];
		delete[] _value;
		this->_value = tmp._value;
		this->_size = tmp.size();
		tmp._value = NULL;
	}
	return *this;
};

template <typename T> const char *Array<T>::OutOfRange::what() const throw() {
	return "Invalid index: out of range";
}

template <typename T> T const &Array<T>::operator[](unsigned int index) const {
	if (index >= this->size())
		throw OutOfRange();
	return _value[index];
};

template <typename T> T &Array<T>::operator[](unsigned int index) {
	if (index >= this->size())
		throw OutOfRange();
	return _value[index];
};

template <typename T> unsigned int Array<T>::size() const {
	return _size;
};
