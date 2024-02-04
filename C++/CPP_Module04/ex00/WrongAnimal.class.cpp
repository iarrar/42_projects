#include "WrongAnimal.class.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "Constructeur par default du WrongAnimal de base" << std::endl;
    this->type = "WrongAnimal Standard";
}

std::string   WrongAnimal::getType(void) const
{
    return (this->type);    
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "Pas de chichi, pas de BlaBla (Faux Animal)" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
	this->type = src.type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructeur WA" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & src)
{
    this->type = src.type;
    return (*this);
}
