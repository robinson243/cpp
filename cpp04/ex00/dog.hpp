#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	~Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	virtual std::string getType() const;
	virtual void makeSound() const;
};

#endif