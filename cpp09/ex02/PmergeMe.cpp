/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 23:47:44 by romukena          #+#    #+#             */
/*   Updated: 2026/04/02 17:33:14 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*================= All =================*/

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

int PmergeMe::Jacobsthal(int n)
{
    if (n == 0)
		return 0;
    if (n == 1)
		return 1;
    int n0 = 0, n1 = 1;
    for (int i = 2; i <= n; i++)
    {
        int next = n1 + 2 * n0;
        n0 = n1;
        n1 = next;
    }
    return n1;
}

bool PmergeMe::isParam (std::string &line)
{
    std::string::const_iterator it = line.begin();
    while (it != line.end() && std::isdigit(*it)) ++it;
    return !line.empty() && it == line.end();
}

std::string PmergeMe:: joinArgs(int ac, char **av)
{
	std::string res;
	for (size_t i = 1; (int)i < ac; i++)
	{
		res.append(av[i]);
		if ((int)i == ac - 1)
			break;
		res.append(" ");
	}
	return res;
}
/*================= Vector =================*/

bool PmergeMe::isDuplicate(std::vector<int> &vec)
{
	std::vector<int>::iterator it;
	for (size_t i = 0; i < vec.size(); i++)
	{
		it = std::find(vec.begin() + i + 1, vec.end(), vec[i]);
		if (it != vec.end())
			return false;
	}
	return true;
}

bool PmergeMe::initVec(const char *s)
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
			long val = std::strtol(strToAdd.c_str(),NULL, 10 );
			if (!isParam(strToAdd) || val > INT_MAX)
				return false;
			this->vec.push_back(atoi(strToAdd.c_str()));
		}
		while (isspace(str[i]) != 0)
		{
			i++;
		}
	}
	return true;
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
	std::vector<int> orginalHigherPair;
	std::vector<int> higherPair;
	std::vector<int> small;
	if (grands.size() <= 1)
		return grands;
	vecPair = makePair(grands);
	doGreatPair(vecPair);
	small = lowPair(vecPair);
	higherPair = highPair(vecPair);
	orginalHigherPair = higherPair;
	higherPair = sortVec(higherPair);
	std::vector<bool> used(orginalHigherPair.size(), false);
    std::vector<int> newSmall;
    for (size_t i = 0; i < higherPair.size(); i++)
    {
        for (size_t j = 0; j < orginalHigherPair.size(); j++)
        {
            if (orginalHigherPair[j] == higherPair[i] && used[j] == false)
            {
                newSmall.push_back(small[j]);
                used[j] = true;
                break;
            }
        }
    }
    small = newSmall;
	std::vector<int> sortedHigherPair = higherPair;
	if (small[0] != -1)
		higherPair.insert(higherPair.begin() , small[0]);
	
	std::vector<int> order = buildJacobOrder(small.size());
	
	for (size_t i = 0; i < order.size(); i++)
	{
		size_t position  = std::find(higherPair.begin(), higherPair.end(), sortedHigherPair[order[i]]) - higherPair.begin();
		if (small[order[i]] != -1)
		{
			binaryInsert(higherPair, small[order[i]], position + 1);
		}
	}
	return higherPair;
}

std::vector<int> PmergeMe::getVec()
{
	return vec;
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
	while ((size_t)Jacobsthal(n) < size)
	{
		int curr = Jacobsthal(n);
		int prev = Jacobsthal(n - 1);
        for (int j = curr - 1; j >= prev; j--)
        {
            if (j < (int)size)
                order.push_back(j);
        }
        n++;
	}
	size_t j = Jacobsthal(n - 1);
	while ( j < size)
		{
			order.push_back(j);
			j++;
		}
	return order;
};


/*================= Deque =================*/



bool PmergeMe::initDeque(const char *s)
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
			long val = std::strtol(strToAdd.c_str(),NULL, 10 );
			if (!isParam(strToAdd) || val > INT_MAX)
				return false;
			if (!isParam(strToAdd))
				return false;
			this->deque.push_back(atoi(strToAdd.c_str()));
		}
		while (isspace(str[i]) != 0)
		{
			i++;
		}
	}
	return true;
};

std::deque<std::pair<int, int> > PmergeMe::makePair(std::deque<int> &grands)
{
	size_t i = 0;
	std::deque<std::pair<int, int> > vecPair;

	while (i + 1 < (grands.size()))
	{
		vecPair.push_back(std::make_pair(grands[i], grands[i + 1]));
		i += 2;
	}
	if (grands.size() % 2 == 1)
		vecPair.push_back(std::make_pair(grands[grands.size() - 1], -1));

	return vecPair;
}

void PmergeMe::doGreatPair(std::deque<std::pair<int, int> > &vecPair)
{
	for (size_t i = 0; i < vecPair.size(); i++)
	{
		if (vecPair[i].first > vecPair[i].second)
			std::swap(vecPair[i].first, vecPair[i].second);
	}
}

std::deque<int> PmergeMe::lowPair(std::deque<std::pair<int,int> >& vecPair)
{
    std::deque<int> small;

    for (size_t i = 0; i < vecPair.size(); i++)
        small.push_back(vecPair[i].first);

    return small;
}

std::deque<int> PmergeMe::highPair(std::deque<std::pair<int, int> > &vecPair)
{
	std::deque<int> pair;
	for (size_t i = 0; i < vecPair.size(); i++)
	{
		pair.push_back(vecPair[i].second);
	}
	return pair;
}

std::deque<int> PmergeMe::sortDeque(std::deque<int> grands)
{
	std::deque<std::pair<int, int> > vecPair;
	std::deque<int> orginalHigherPair;
	std::deque<int> higherPair;
	std::deque<int> small;
	if (grands.size() <= 1)
		return grands;
	vecPair = makePair(grands);
	doGreatPair(vecPair);
	small = lowPair(vecPair);
	higherPair = highPair(vecPair);
	orginalHigherPair = higherPair;
	higherPair = sortDeque(higherPair);
	std::deque<bool> used(orginalHigherPair.size(), false);
    std::deque<int> newSmall;
    for (size_t i = 0; i < higherPair.size(); i++)
    {
        for (size_t j = 0; j < orginalHigherPair.size(); j++)
        {
            if (orginalHigherPair[j] == higherPair[i] && used[j] == false)
            {
                newSmall.push_back(small[j]);
                used[j] = true;
                break;
            }
        }
    }
    small = newSmall;
	std::deque<int> sortedHigherPair = higherPair;
	if (small[0] != -1)
		higherPair.insert(higherPair.begin() , small[0]);
	
	std::deque<int> order = buildJacobOrderDeque(small.size());
	
	for (size_t i = 0; i < order.size(); i++)
	{
		size_t position  = std::find(higherPair.begin(), higherPair.end(), sortedHigherPair[order[i]]) - higherPair.begin();
		if (small[order[i]] != -1)
		{
			binaryInsert(higherPair, small[order[i]], position + 1);
		}
	}
	return higherPair;
}

std::deque<int> PmergeMe::getDeque()
{
	return deque;
}

void PmergeMe::binaryInsert(std::deque<int> &result, int val, size_t bound)
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

std::deque<int> PmergeMe::buildJacobOrderDeque(size_t size)
{
	std::deque<int> order;
	size_t n = 2;
	while ((size_t)Jacobsthal(n) < size)
	{
		int curr = Jacobsthal(n);
		int prev = Jacobsthal(n - 1);
        for (int j = curr - 1; j >= prev; j--)
        {
            if (j < (int)size)
                order.push_back(j);
        }
        n++;
	}
	size_t j = Jacobsthal(n - 1);
	while ( j < size)
		{
			order.push_back(j);
			j++;
		}
	return order;
};