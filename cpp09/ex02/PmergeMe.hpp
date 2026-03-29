/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 23:43:53 by romukena          #+#    #+#             */
/*   Updated: 2026/03/30 01:33:22 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
#include <limits>

class PmergeMe
{
private:
	std::vector<int> vec;
	std::deque<int> deque;

public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	void initVec(char *s);
	std::vector<std::pair<int, int> > makePair();
	void doGreatPair(std::vector<std::pair<int, int> > &vecPair);
};

#endif
