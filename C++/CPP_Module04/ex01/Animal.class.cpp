#include "Animal.class.hpp"

Animal::Animal()
{
    std::cout << "Constructeur par default de l'Animal de base" << std::endl;
    this->type = "Animal Standard";
}

std::string   Animal::getType(void) const
{
    return (this->type);    
}

void    Animal::makeSound(void) const
{
    std::cout << "Pas de chichi, pas de BlaBla" << std::endl;
}

Animal::Animal(Animal const & src)
{
    *this = src;
}

Animal::~Animal()
{
    std::cout << "Destructeur de la classe Animal" << std::endl;
}

Animal & Animal::operator=(Animal const & src)
{
    this->type = src.type;
    return (*this);
}
