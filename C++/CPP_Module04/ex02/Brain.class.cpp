#include "Brain.class.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor" << std::endl;
    this->ideas = new std::string[100];
    
}

Brain::Brain(Brain const & src)
{
    int i = 0;
    this->ideas = new std::string[100];
    while (i < 100)
    {
        this->ideas[i] = "copie de " + src.ideas[i];
        i++;
    }
}

Brain::~Brain()
{
    std::cout << "Brain destructor" << std::endl;
    delete [] this->ideas;
}

Brain & Brain::operator=(Brain const & src)
{
    int i = 0;
    if (this != &src)
    {
        delete [] ideas;
        ideas = new std::string[100];
        while (i < 100)
        {
            ideas[i] = src.ideas[i];
            i++;
        }
    }
    return (*this);
}

