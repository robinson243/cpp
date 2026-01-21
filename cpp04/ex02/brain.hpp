/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:04:47 by romukena          #+#    #+#             */
/*   Updated: 2026/01/21 01:14:39 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
protected:
	std::string ideas[100];

public:
	Brain();
	virtual ~Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
};

#endif