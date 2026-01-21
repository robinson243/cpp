#ifndef CAT_HPP
#define CAT_HPP

#include "animal.hpp"
#include "brain.hpp"
#include <iostream>

class Cat : public AAnimal
{
private:
	Brain *_attribute;

public:
	Cat();
	virtual ~Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	virtual void makeSound() const;
};

#endif