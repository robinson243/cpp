/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 23:43:53 by romukena          #+#    #+#             */
/*   Updated: 2026/04/01 10:34:57 by romukena         ###   ########.fr       */
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
	/* ====================== all ======================= */
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	int Jacobsthal(int n);
	bool isParam (std::string &line);
	/* ====================== Vector ======================= */
	bool initVec(char *s);
	std::vector<std::pair<int, int> > makePair(std::vector<int> &grands);
	void doGreatPair(std::vector<std::pair<int, int> > &vecPair);
	std::vector<int> highPair(std::vector<std::pair<int, int> > &vecPair );
	std::vector<int> lowPair(std::vector<std::pair<int,int> >& vecPair);
	std::vector<int> sortVec(std::vector<int> grands);
	std::vector<int> getVec();
	void binaryInsert(std::vector<int> &result, int val, size_t bound);
	std::vector<int> buildJacobOrder(size_t size);
	/* ====================== Deque ======================= */
	bool initDeque(char *s);
	std::deque<std::pair<int, int> > makePair(std::deque<int> &grands);
	void doGreatPair(std::deque<std::pair<int, int> > &vecPair);
	std::deque<int> highPair(std::deque<std::pair<int, int> > &vecPair );
	std::deque<int> lowPair(std::deque<std::pair<int,int> >& vecPair);
	std::deque<int> sortDeque(std::deque<int> grands);
	std::deque<int> getDeque();
	void binaryInsert(std::deque<int> &result, int val, size_t bound);
	std::deque<int> buildJacobOrderDeque(size_t size);
};


#endif
