/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 11:47:25 by romukena          #+#    #+#             */
/*   Updated: 2026/03/09 12:55:02 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
    uintptr_t value;
};

class Serializer
{
public:
	static uintptr_t serialize(Data *ptr);
	static Data	*deserialize(uintptr_t raw);
private:
    Serializer();
    ~Serializer();
    Serializer(const Serializer &other);
    Serializer &operator=(const Serializer &other);
};



#endif