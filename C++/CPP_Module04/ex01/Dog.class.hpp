#ifndef DOG_H
#define DOG_H
#include "Animal.class.hpp"
#include "Brain.class.hpp"

class Dog : virtual public Animal
{
    public:
        Dog();
        Dog(Dog const & src);
        virtual ~Dog();
        Dog& operator=(Dog const & src);
        void    makeSound(void) const;


    private:
        Brain *DogBrain;
        std::string type;
        
};

#endif