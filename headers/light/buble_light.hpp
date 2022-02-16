#ifndef BUBLE_LIGHT_HPP
#define BUBLE_LIGHT_HPP
#include "light.hpp"

class Buble_light : public Light
{
public:
    Point3 centre;
    float rayon;

    Buble_light();

    Buble_light(Point3 c, float r);

    float get_inter(const Point3 &p, Vector3 &L, Color &c); // get the intersection between a ray and the light

    float get_inter_ray(const Ray &r, Point3 p); // get the intersection between a ray and the light for the shadows

    void get_xml(pugi::xml_node bl); // load this object by xml
};

#endif