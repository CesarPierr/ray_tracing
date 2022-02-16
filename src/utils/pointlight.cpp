#include "utils/pointlight.hpp"

Ray::Ray()
{
    src = Point3(0.0, 0.0, 0.0);
    dir = Point3(1.0, 0.0, 0.0);
    has_been_reflected = -1;
    pix.r() = 0;
    pix.g() = 0;
    pix.b() = 0;
};

Ray::Ray(Point3 p, Vector3 d) : src(p)
{
    dir = Normalize(d);
    has_been_reflected = -1;
    pix.r() = 0;
    pix.g() = 0;
    pix.b() = 0;
};

Vector3 Ray::Normalize(Vector3 v)
{
    return v / v.norm();
}