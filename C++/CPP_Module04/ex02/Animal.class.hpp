#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>
#include <iomanip>

class AAnimal
{
    public:
        AAnimal();
        AAnimal(AAnimal const & src);
        virtual ~AAnimal();
       AAnimal& operator=(AAnimal const & src);
       virtual std::string getType(void) const = 0;
       virtual void makeSound(void) const = 0;

    protected:
        std::string type;

};

#endif