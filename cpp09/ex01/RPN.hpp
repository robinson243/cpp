/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:19:01 by romukena          #+#    #+#             */
/*   Updated: 2026/03/26 15:15:49 by romukena         ###   ########.fr       */
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
	std::stack<std::string> number;
	std::stack<std::string> op;

  public:
	RPN();
	~RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	std::stack<std::string> getNumber();
	std::stack<std::string> getOp();
	std::stack<std::string> getArray();
	RPN(char *s);
	void showElement();
	bool isValid();
  void goodOrder();
};
bool isInt(std::string a);
bool isOperator(std::string a);

#endif