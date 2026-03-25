/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:19:01 by romukena          #+#    #+#             */
/*   Updated: 2026/03/25 16:32:50 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RNP_HPP
#define RNP_HPP

#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

class RPN {
  private:
	std::stack<std::string> array;
  public:
	RPN();
	~RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
    std::stack<std::string> getArray();
    RPN(char *s);
    void showElement();
};

#endif