#include "Weapon.hpp"

Weapon::Weapon() {};
Weapon::~Weapon() {};

Weapon::Weapon(std::string _nType) : _type(_nType) {}

const std::string& Weapon::getType()
{
	return (_type);
}

void Weapon::setType(std::string _nType)
{
	this->_type = _nType;
}
