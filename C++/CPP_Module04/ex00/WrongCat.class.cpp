#include "WrongCat.class.hpp"

WrongCat::WrongCat()
{
    std::cout << "Constructeur par default du faux chat qui fait miaou miaou" << std::endl;
    this->type = "WrongCat";
}

void    WrongCat::makeSound(void) const
{
    std::cout << "MiiiiaaaaAAAAAouuuuuuuuu" << std::endl;
}

WrongCat::WrongCat(WrongCat const & src)
{
    this->type = src.type;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructeur WC" << std::endl;
}

WrongCat & WrongCat::operator=(WrongCat const & src)
{
    this->type = src.type;
    return (*this);
}
