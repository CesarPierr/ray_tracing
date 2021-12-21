#ifndef ENVIRONNEMENT_HPP
#define ENVIRONNEMENT_HPP
#include "materiaux.hpp"


class Env
{
    public :
        float min_x,max_x,min_y,max_y,min_z,max_z;

        Env(){};
        Env(const Env &env){};

};
#endif