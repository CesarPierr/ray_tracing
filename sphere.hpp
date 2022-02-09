#ifndef SPHERE_HPP
#define SPHERE_HPP
#include "objet.hpp"

class Sphere : public Objet
{

public:
    Point3 centre;
    float rayon;

    Sphere();
    Sphere(Point3 c, float r);
    Sphere(Point3 c, float r, Materiaux m);

    ~Sphere(){};

    float get_inter(const Ray &r, Point3 &p);

    Materiaux get_mat(const Point3 &p)
    {
        return mat;
    }

    Vector3 get_normal(const Point3 &inter);

    Ray get_refracted_ray(const Ray &inc_ray, const Point3 &p, const Vector3 &normale);
};
#endif