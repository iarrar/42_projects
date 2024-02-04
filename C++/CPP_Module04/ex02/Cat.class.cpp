#include "Cat.class.hpp"


Cat::Cat()
{
	std::cout << "Constructeur par default du chat qui fait miaou miaou" << std::endl;
	this->type = "Cat";
	this->CatBrain = new Brain;
}



void    Cat::makeSound(void) const
{
	std::cout << "MiiiiaaaaAAAAAouuuuuuuuu" << std::endl;
}

Cat::Cat(Cat const & src)
{
	CatBrain = new Brain(*(src.CatBrain));
	this->type = src.type;
	return ;
}
std::string    Cat::getType() const
{
	return (this->type);
}

Cat::~Cat()
{
	delete this->CatBrain;
	std::cout << "Cat destructor called " << std::endl;
}

Cat & Cat::operator=(Cat const & src)
{
	if (this != &src)
	{
		delete this->CatBrain;
		this->CatBrain = new Brain(*(src.CatBrain));
		this->type = src.type;
	}
	return (*this);
}

void    Cat::affBrainAdress() const
{
	std::cout << "Brain adress is " << &this->CatBrain <<std::endl;
}