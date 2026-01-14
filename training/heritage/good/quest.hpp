#ifndef QUEST_HPP
#define QUEST_HPP

#include <iostream>
#include <string>

class Quest
{
public:
	Quest() = delete;
	Quest(const std::string &name, const std::string &description) noexcept;

private:
	std::string _name;
	std::string _description;
};

#endif