/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 23:47:44 by romukena          #+#    #+#             */
/*   Updated: 2026/03/31 14:57:58 by romukena         ###   ########.fr       */
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

std::vector<int> PmergeMe::lowPair(std::vector<std::pair<int,int> >& vecPair)
{
    std::vector<int> small;

    for (size_t i = 0; i < vecPair.size(); i++)
        small.push_back(vecPair[i].first);

    return small;
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
	std::vector<int> result;
	std::vector<int> higherPair;
	std::vector<int> small;
	if (grands.size() <= 1)
		return grands;
	vecPair = makePair(grands);
	doGreatPair(vecPair);
	small = lowPair(vecPair);
	higherPair = highPair(vecPair);
	higherPair = sortVec(higherPair);
	return higherPair;
}

std::vector<int> PmergeMe::getVec()
{
	return vec;
}

int PmergeMe:: Jacobsthal(int n)
{
    // base case
    if (n == 0)
        return 0;

    // base case
    if (n == 1)
        return 1;

    // recursive step.
    return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}

void PmergeMe::binaryInsert(std::vector<int> &result, int val, size_t bound)
{
	int low = 0;
    int high = bound;
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (result[mid] < val)
            low = mid + 1;
		else
			high = mid;
	}
	result.insert(result.begin() + low, val);
}

std::vector<int> PmergeMe::buildJacobOrder(size_t size)
{
	std::vector<int> order;
	size_t n = 2;
	for (n ; Jacobsthal(n) < size; n++)
	{
		
		for (int j = Jacobsthal(n) - 1; j >= Jacobsthal(n-1) ; j--)
		{
			if (j <(int)size)
				order.push_back(j);
		}
	}
	for (int j = Jacobsthal(n - 1); j < size ; j++)
		{
			order.push_back(j);
		}
	return order;
}