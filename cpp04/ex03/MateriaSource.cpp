/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:39:57 by romukena          #+#    #+#             */
/*   Updated: 2026/01/24 12:03:36 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
}
MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		delete this->_materias[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++)
			delete this->_materias[i];
		for (int i = 0; i < 4; i++) {
			if (other._materias[i]) {
				this->_materias[i] = other._materias[i]->clone();
			} else {
				this->_materias[i] = NULL;
			}
		}
	}
	return *this;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	for (int i = 0; i < 4; i++) {
		if (other._materias[i]) {
			this->_materias[i] = other._materias[i]->clone();
		} else {
			this->_materias[i] = NULL;
		}
	}
}

void MateriaSource::learnMateria(AMateria *target) {
	for (int i = 0; i < 4; i++) {
		if (this->_materias[i] == NULL) {
			this->_materias[i] = target->clone();
			delete target;
			break;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (_materias[i]) {
			if (_materias[i]->getType() == type) {
				return _materias[i]->clone();
			}
		}
	}
	return NULL;
}