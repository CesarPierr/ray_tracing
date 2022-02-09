#ifndef LIGHT_HPP
#define LIGHT_HPP
#include "color.hpp"
#include "pointlight.hpp"

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
    power_type power;

public:
    Color light_color;
    virtual float get_inter(const Point3 &p, Vector3 &L, Color &c) = 0;
    virtual float get_inter_ray(const Ray &r, Point3 p) = 0;
    virtual Color get_color(const Point3 &p, float distance = 1)
    {
        switch (power)
        {
        case low_dispersion:
            return light_color * pow(1 / distance, 0.1);
            break;
        case normal_dispersion:
            return light_color * pow(1 / distance, 1);
            break;
        case high_dispersion:
            return light_color * pow(1 / distance, 5);
            break;
        case uniform:
            return light_color;
            break;
        default:
            return light_color;
        }
    }
};

#endif