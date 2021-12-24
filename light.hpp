#ifndef LIGHT_HPP
#define LIGHT_HPP
#include "color.hpp"
#include "pointlight.hpp"
class Light 
{
    static const int type = 0;
    public :
        Color light_color;
        virtual float get_inter(const Point3& p,Vector3& L, Color& c) = 0;
};

#endif