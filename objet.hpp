#ifndef OBJET_HPP
#define OBJET_HPP
#include "materiaux.hpp"
#include "pointlight.hpp"
class Objet
{
    static const int type = 1;

public:
    Materiaux mat;

    virtual float get_inter(const Ray &r, Point3 &test) = 0;
    virtual Vector3 get_normal(const Point3 &inter) = 0;
    virtual Materiaux get_mat(const Point3 &p) = 0;
    virtual Ray get_refracted_ray(const Ray &inc_ray, const Point3 &p, const Vector3 &normale) = 0;
    virtual Ray get_reflected_ray(const Ray &inc_ray, const Point3 &p, const Vector3 &normale)
    {
        Vector3 dir_reflec = inc_ray.dir - (2 * normale.dot(inc_ray.dir) * normale);
        Ray reflec(p, dir_reflec);
        reflec.puissance = 0.5;
        return reflec;
    }
};
#endif