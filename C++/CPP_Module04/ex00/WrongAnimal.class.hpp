#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H
#include <iostream>
#include <string>
#include <iomanip>

class WrongAnimal
{
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(WrongAnimal const & src);
        virtual ~WrongAnimal();
       WrongAnimal& operator=(WrongAnimal const & src);
       std::string getType(void) const;
       void makeSound(void) const;

    protected:
        std::string type;

};

#endif