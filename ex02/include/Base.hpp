#pragma once

#include <random>

class Base 
{
    public:
        virtual ~Base() {}
};

Base *generate(void);
void identify(Base* p);
void identify(Base& p);
