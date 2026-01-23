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
	virtual ~Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	virtual void makeSound() const;
};

#endif