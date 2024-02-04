#ifndef CAT_H
#define CAT_H
#include "Animal.class.hpp"
#include "Brain.class.hpp"
#include <iostream>
#include <string>

class Cat : virtual public AAnimal
{
    public:
        Cat();
        Cat(Cat const & src);
        virtual ~Cat();
        Cat& operator=(Cat const & src);
        void    makeSound(void) const;
        std::string getType() const;
        void affBrainAdress() const;


    private:
        std::string type;
        Brain   *CatBrain;

};

#endif