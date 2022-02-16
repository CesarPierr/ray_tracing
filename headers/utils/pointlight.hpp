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
    float puissance = 1;
    int has_been_reflected = -1;
    int has_been_refracted = -1;

    Ray();

    Ray(Point3 p, Vector3 d);

    Vector3 Normalize(Vector3 v);

    ~Ray(){};
};
#endif