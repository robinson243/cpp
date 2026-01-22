/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:11:25 by romukena          #+#    #+#             */
/*   Updated: 2026/01/22 15:19:54 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
  private:
	AMateria *_materias[4];
  public:
	MateriaSource();
	virtual ~MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &other);

	void learnMateria(AMateria *);
	AMateria *createMateria(std::string const &type);
};
