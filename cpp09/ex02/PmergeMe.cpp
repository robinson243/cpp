/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 23:47:44 by romukena          #+#    #+#             */
/*   Updated: 2026/03/31 00:34:21 by romukena         ###   ########.fr       */
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

std::vector<std::pair<int, int> > PmergeMe::makePair(std::vector<int> &grands)
{
	size_t i = 0;
	std::vector<std::pair<int, int> > vecPair;

	while (i + 1 < (grands.size()))
	{
		vecPair.push_back(std::make_pair(grands[i], grands[i + 1]));
		i += 2;
	}
	if (grands.size() % 2 == 1)
		vecPair.push_back(std::make_pair(grands[grands.size() - 1], -1));

	return vecPair;
}

void PmergeMe::doGreatPair(std::vector<std::pair<int, int> > &vecPair)
{
	for (size_t i = 0; i < vecPair.size(); i++)
	{
		if (vecPair[i].first > vecPair[i].second)
			std::swap(vecPair[i].first, vecPair[i].second);
	}
}

std::vector<int> PmergeMe::highPair(std::vector<std::pair<int, int> > &vecPair)
{
	std::vector<int> pair;
	for (size_t i = 0; i < vecPair.size(); i++)
	{
		pair.push_back(vecPair[i].second);
	}
	return pair;
}

std::vector<int> PmergeMe::sortVec(std::vector<int> grands)
{
	std::vector<std::pair<int, int> > vecPair;
	std::vector<int> higherPair;
	if (grands.size() <= 1)
		return grands;
	vecPair = makePair(grands);
	doGreatPair(vecPair);
	higherPair = highPair(vecPair);
	higherPair = sortVec(higherPair);
	return higherPair;
}

std::vector<int> PmergeMe::getVec()
{
	return vec;
}
