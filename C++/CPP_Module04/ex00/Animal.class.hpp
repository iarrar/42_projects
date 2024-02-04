#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>
#include <iomanip>

class Animal
{
    public:
        Animal();
        Animal(std::string type);
        Animal(Animal const & src);
        virtual ~Animal();
       Animal& operator=(Animal const & src);
       std::string getType(void) const;
       virtual void makeSound(void) const;

    protected:
        std::string type;

};

#endif