#include "utils/pointlight.hpp"

Ray::Ray()
{
    src = Point3(0.0, 0.0, 0.0);
    dir = Point3(1.0, 0.0, 0.0);
    has_been_reflected = -1;//num of last objet that reflected the light
    has_been_refracted = -1;//num of last objet that refracted the light
    pix.r() = 0;
    pix.g() = 0;
    pix.b() = 0;
};

Ray::Ray(Point3 p, Vector3 d) : src(p)
{
    dir = Normalize(d);
    has_been_reflected = -1;
    has_been_refracted = -1;
    pix.r() = 0;
    pix.g() = 0;
    pix.b() = 0;
};

Vector3 Ray::Normalize(Vector3 v)
{
    return v / v.norm();
}