#ifndef BUBLE_LIGHT_HPP
#define BUBLE_LIGHT_HPP
#include "light.hpp"

class Buble_light : public Light
{
    public :
        
        Point3 centre;
        float rayon;


        Buble_light() : centre(Point3(0.0,0.0,0.0)), rayon(1) {}
        Buble_light(Point3 c, float r) : centre(c), rayon(r) {}

        float get_inter(const Point3& p,Vector3& L, Color& c)
        {
            L = centre-p;
            float distance = L.norm();
            L = L/distance;
            c = light_color;
            return distance - rayon;
        }
};

#endif