#ifndef OBJET_HPP
#define OBJET_HPP
#include "utils/materiaux.hpp"
#include "xml/pugixml.hpp"
#include "utils/pointlight.hpp"
class Objet
{
    static const int type = 1;

public:
    Materiaux mat;

    virtual float get_inter(const Ray &r, Point3 &test) = 0;
    virtual Vector3 get_normal(const Point3 &inter) = 0;
    virtual Materiaux get_mat(const Point3 &p) = 0;
    virtual bool ray_in(const Ray &r) = 0;

    virtual void get_xml(pugi::xml_node obj) = 0;

    virtual Ray get_refracted_ray(const Ray &inc_ray, const Point3 &p, Vector3 &normale)
    {
        if (ray_in(inc_ray))
        {
            float eta = mat.in_refractive_index / mat.out_refractive_index;
            float c1 = -normale.dot(inc_ray.dir);
            float c2 = std::sqrt(1 - eta * eta * (1 - c1 * c1));
            Vector3 dir = eta * inc_ray.dir - (eta * c1 - c2) * normale;
            Ray ret(p, dir);
            return ret;
        }
        else
        {
            float eta = mat.out_refractive_index / mat.in_refractive_index;
            float c1 = normale.dot(inc_ray.dir);
            float c2 = std::sqrt(1 - eta * eta * (1 - c1 * c1));
            Vector3 dir = eta * inc_ray.dir + (eta * c1 - c2) * normale;
            Ray ret(p, dir);
            return ret;
        }
    }
    virtual Ray get_reflected_ray(const Ray &inc_ray, Point3 p, const Vector3 &normale)
    {
        Vector3 dir_reflec = inc_ray.dir - (2 * normale.dot(inc_ray.dir) * normale);
        Ray reflec(p, dir_reflec);
        return reflec;
    }
};
#endif