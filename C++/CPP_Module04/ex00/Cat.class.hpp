#ifndef CAT_H
#define CAT_H
#include "Animal.class.hpp"
#include <iostream>
#include <string>

class Cat : public Animal
{
    public:
        Cat();
        Cat(std::string type);
        Cat(Cat const & src);
        virtual ~Cat();
        Cat& operator=(Cat const & src);
                void    makeSound(void) const;


    private:

};

#endif