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
    float puissance = 1;         // power of the ray
    int has_been_reflected = -1; // index of last object that reflected this ray
    int has_been_refracted = -1; // index of last object that refracted this ray

    Ray();

    Ray(Point3 p, Vector3 d);

    Vector3 Normalize(Vector3 v); // set the dir vector norm to 1

    ~Ray(){};
};
#endif