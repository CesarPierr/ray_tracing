#ifndef POINTLIGHT_HPP
#define POINTLIGHT_HPP
#include "pointVector.hpp"
#include "color.hpp"
class Ray
{
    public :
        Point3 src;
        Vector3 dir;
        Color pix;
        float puissance;
        Ray()
        {
            src = Point3(0.0,0.0,0.0);
            dir = Point3(1.0,0.0,0.0);
            pix.r() = 0; pix.g() = 0; pix.b() = 0;
        };
        Ray(Point3 p, Vector3 d) : src(p)
        {
            dir = Normalize(d);
            pix.r() = 0; pix.g() = 0; pix.b() = 0;
        };

        Vector3 Normalize(Vector3 v)
        {
            return v/v.norm();
        } 
        ~Ray(){};
};
#endif