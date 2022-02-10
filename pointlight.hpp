#ifndef POINTLIGHT_HPP
#define POINTLIGHT_HPP
#include "pointVector.hpp"
#include "color.hpp"
class Ray
{
public:
    Point3 src;
    Vector3 dir;
    Color pix;
    
    Ray();

    Ray(Point3 p, Vector3 d);

    Vector3 Normalize(Vector3 v);

    ~Ray(){};
};
#endif