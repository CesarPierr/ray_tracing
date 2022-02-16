#ifndef LIGHT_HPP
#define LIGHT_HPP
#include "utils/color.hpp"
#include "utils/pointlight.hpp"
#include "xml/pugixml.hpp"

enum power_type
{
    low_dispersion,
    normal_dispersion,
    uniform,
    high_dispersion
};

class Light
{
    static const int type = 0;

public:
    power_type power;
    Color light_color;
    virtual float get_inter(const Point3 &p, Vector3 &L, Color &c) = 0; // get the intersection between a ray and the light
    virtual float get_inter_ray(const Ray &r, Point3 p) = 0;            // get the intersection between a ray and the light for shadows
    virtual void get_xml(pugi::xml_node light) = 0;                     // load this object by xml

    virtual Color get_color(const Point3 &p, float distance = 1) // get the color of the light depending on the distance from it
    {
        Color r;
        switch (power)
        {
        case low_dispersion:
            r = light_color * powf(1 / distance, 0.5);
            break;
        case normal_dispersion:
            r = light_color * powf(1 / distance, 0.7);
            break;
        case high_dispersion:
            r = light_color * powf(1 / distance, 1);
            break;
        case uniform:
            r = light_color;
            break;
        default:
            r = light_color;
        }
        return r;
    }
};

#endif