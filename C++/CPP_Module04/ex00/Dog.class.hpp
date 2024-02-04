#ifndef DOG_H
#define DOG_H
#include "Animal.class.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog (std::string type);
        Dog(Dog const & src);
        virtual ~Dog();
        Dog& operator=(Dog const & src);
        void    makeSound(void) const;


    private:

};

#endif