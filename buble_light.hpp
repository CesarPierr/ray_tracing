#ifndef BUBLE_LIGHT_HPP
#define BUBLE_LIGHT_HPP
#include "light.hpp"

class Buble_light : public Light
{
public:
    Point3 centre;
    float rayon;
    power_type normal_dispersion;

    Buble_light();

    Buble_light(Point3 c, float r);

    float get_inter(const Point3 &p, Vector3 &L, Color &c);

    float get_inter_ray(const Ray &r, Point3 p);
};

#endif