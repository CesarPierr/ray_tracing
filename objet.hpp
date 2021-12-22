#ifndef OBJET_HPP
#define OBJET_HPP
#include "materiaux.hpp"
class Objet
{
    public : 
        Materiaux ext_m;
        Materiaux int_m;
        virtual Point3 intersect();
        virtual Vector3 normal(Point3 inter, bool& omw);

}
#endif