/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:55:39 by romukena          #+#    #+#             */
/*   Updated: 2026/03/19 15:35:47 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T> MutantStack<T>::MutantStack(){};

template <typename T> MutantStack<T>::~MutantStack(){};

template <typename T> MutantStack<T>::MutantStack(const MutantStack<T> &other) {
	if (this != &other) {
		;
	}
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &other) {
	if (this != &other) {
		;
	}
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return this->c.begin();
}

template <typename T> typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
};

// template <typename T>
// template <typename T>
// template <typename T>
// template <typename T>