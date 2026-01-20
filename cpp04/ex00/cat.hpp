#ifndef CAT_HPP
#define CAT_HPP

#include "animal.hpp"
#include <iostream>

class Cat : public Animal
{
public:
	Cat();
	virtual ~Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	virtual std::string getType() const;
	virtual void makeSound() const;
};

#endif