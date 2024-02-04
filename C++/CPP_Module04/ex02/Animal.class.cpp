#include "Animal.class.hpp"

AAnimal::AAnimal()
{
    std::cout << "Constructeur par default de l'AAnimal de base" << std::endl;
    this->type = "AAnimal Standard";
}

std::string   AAnimal::getType(void) const
{
    return (this->type);    
}

void    AAnimal::makeSound(void) const
{
    std::cout << "Pas de chichi, pas de BlaBla" << std::endl;
}

AAnimal::AAnimal(AAnimal const & src)
{
    *this = src;
}

AAnimal::~AAnimal()
{
    std::cout << "Destructeur de la classe AAnimal" << std::endl;
}

AAnimal & AAnimal::operator=(AAnimal const & src)
{
    this->type = src.type;
    return (*this);
}
