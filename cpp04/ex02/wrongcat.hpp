/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongcat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 12:56:02 by romukena          #+#    #+#             */
/*   Updated: 2026/01/23 13:02:10 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "wronganimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal {
  public:
	WrongCat();
	virtual ~WrongCat();
	WrongCat(const WrongCat &other);
	WrongCat &operator=(const WrongCat &other);
	std::string getType() const;
	void makeSound() const;
};

#endif