#include "Dog.class.hpp"


Dog::Dog()
{
    std::cout << "Constructeur par defaut du chien qui fait ouaf ouaf" << std::endl;
    this->type = "Dog";
    this->DogBrain = new Brain;
}

Dog::Dog(Dog const & src)
{
    this->DogBrain = new Brain(*(src.DogBrain));
    this->type = src.type;
}

Dog::~Dog()
{
    delete DogBrain;
    std::cout << "Destructeur de la classe Dog" << std::endl;
}

void    Dog::makeSound(void) const
{
    std::cout << "ouaf ouaf" << std::endl;
}

Dog & Dog::operator=(Dog const & src)
{
    if (this != &src)
    {
        delete this->DogBrain;
        this->DogBrain = new Brain(*(src.DogBrain));
        this->type = src.type;
    }
    return (*this);
}
