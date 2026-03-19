/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 16:36:20 by romukena          #+#    #+#             */
/*   Updated: 2026/03/19 15:35:23 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <iostream>
#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
  public:
	typedef typename std::deque<T>::iterator iterator;
	MutantStack();
	~MutantStack();
	MutantStack(const MutantStack<T> &other);
	MutantStack &operator=(const MutantStack<T> &other);
	iterator begin();
	iterator end();
};

#include "MutantStack.tpp"
#endif