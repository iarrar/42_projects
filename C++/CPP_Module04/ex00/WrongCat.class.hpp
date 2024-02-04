#ifndef WRONGCAT_H
#define WRONGCAT_H
#include "WrongAnimal.class.hpp"
#include <iostream>
#include <string>

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(std::string type);
        WrongCat(WrongCat const & src);
        virtual ~WrongCat();
        WrongCat& operator=(WrongCat const & src);
        void    makeSound(void) const;


    private:

};

#endif