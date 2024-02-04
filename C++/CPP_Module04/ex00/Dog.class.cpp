#include "Dog.class.hpp"

Dog::Dog()
{
    std::cout << "Constructeur par defaut du chien qui fait ouaf ouaf" << std::endl;
    this->type = "Dog";
}

Dog::Dog(Dog const & src)
{
   this->type = src.type;
}

Dog::~Dog()
{
	std::cout << "Destructeur D" << std::endl;
}

void    Dog::makeSound(void) const
{
    std::cout << "ouaf ouaf" << std::endl;
}

Dog & Dog::operator=(Dog const & src)
{
    this->type = src.type;
    return (*this);
}
