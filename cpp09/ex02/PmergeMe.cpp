/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 23:47:44 by romukena          #+#    #+#             */
/*   Updated: 2026/03/30 01:38:25 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {};
PmergeMe::~PmergeMe() {};
PmergeMe::PmergeMe(const PmergeMe &other)
{
	vec = other.vec;
	deque = other.deque;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	vec = other.vec;
	deque = other.deque;
	return *this;
}

void PmergeMe::initVec(char *s)
{
	std::string str(s);
	size_t first;
	size_t last;
	size_t i = 0;
	while (str[i])
	{
		while (isspace(str[i]) != 0 && str[i])
		{
			i++;
		}
		if (isspace(str[i]) == 0)
		{
			first = i;
		}
		while (isspace(str[i]) == 0 && str[i])
		{
			i++;
		}
		if (isspace(str[i]) != 0 || str[i] == '\0')
		{
			last = i;
			std::string strToAdd = str.substr(first, (last - first));
			this->vec.push_back(atoi(strToAdd.c_str()));
		}
		while (isspace(str[i]) != 0)
		{
			i++;
		}
	}
};

std::vector<std::pair<int, int> > PmergeMe::makePair()
{
	size_t i = 0;
	size_t j = 1;
	std::vector<std::pair<int, int> > vecPair;

	while (i < (vec.size()))
	{
		vecPair.push_back(std::make_pair(vec[i], vec[j]));
		i += 2;
		j += 2;
	}
	if (vec.size() % 2 == 1)
		vecPair.push_back(std::make_pair(vec[vec.size() - 1], -1));

	return vecPair;
}

void PmergeMe::doGreatPair(std::vector<std::pair<int, int> > &vecPair)
{
	// std::vector<std::pair<std::string, std::string>> vecPair = this->makePair();
	for (size_t i = 0; i < vecPair.size(); i++)
	{
		if (vecPair[i].first > vecPair[i].second)
			std::swap(vecPair[i].first, vecPair[i].second);
	}
}