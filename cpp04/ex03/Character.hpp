/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:53:24 by romukena          #+#    #+#             */
/*   Updated: 2026/01/22 18:47:03 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character : public ICharacter {
  private:
	std::string _name;
	AMateria *_inventory[4];
  public:
	Character();
	~Character();
	Character(const Character &other);
	Character &operator=(const Character &other);
	Character(const std::string &_otherName);

	virtual std::string const &getName() const;
	virtual void equip(AMateria *m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter &target);
};

#endif