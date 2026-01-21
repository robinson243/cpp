#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "animal.hpp"
#include "brain.hpp"

class Dog : public AAnimal
{
private:
	Brain *_attribute;

public:
	Dog();
	~Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	virtual std::string getType() const;
	virtual void makeSound() const;
};

#endif