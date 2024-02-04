#ifndef BRAIN_H
#define BRAIN_H
#include <iostream>
#include <string>

class Brain
{
    public:
        Brain();
        Brain(Brain const & src);
        virtual ~Brain();
       Brain& operator=(Brain const & src);
       

    protected:
        std::string *ideas;

};

#endif