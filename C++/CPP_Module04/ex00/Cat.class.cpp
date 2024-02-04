#include "Cat.class.hpp"

Cat::Cat()
{
    std::cout << "Constructeur par default du chat qui fait miaou miaou" << std::endl;
    this->type = "Cat";
}

void    Cat::makeSound(void) const
{
    std::cout << "MiiiiaaaaAAAAAouuuuuuuuu" << std::endl;
}

Cat::Cat(Cat const & src)
{
    this->type = src.type;
}

Cat::~Cat()
{
	std::cout << "Destructeur C" << std::endl;
}

Cat & Cat::operator=(Cat const & src)
{
    this->type = src.type;
    return (*this);
}
