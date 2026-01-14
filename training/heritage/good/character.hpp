#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "unit.hpp"

class Character : public Unit
{
public:
	Character() = delete;
	Character(int id, const std::string &name, int level) noexcept;
	int getLevel();

private:
	// int _id;
	// std::string _name;
	int _level;
};

#endif