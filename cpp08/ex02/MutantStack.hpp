/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 16:36:20 by romukena          #+#    #+#             */
/*   Updated: 2026/03/18 18:28:26 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <iostream>
#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
  public:
	using iterator = typename std::deque<T>::iterator;
	MutantStack();
	~MutantStack();
	MutantStack(const MutantStack &other);
	MutantStack &operator=(const MutantStack &other);
	// void push(T other);
	// void pop();
	// T top();
	// size_t size();
	MutantStack<T>::iterator begin(); /*doit retourner un iterateur*/
	MutantStack<T>::iterator end();	  /*doit retourner un iterateur*/
};

#endif