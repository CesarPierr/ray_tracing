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

    virtual float get_inter(const Ray &r, Point3 &test, Vector3 &normale) = 0;
    virtual Materiaux get_mat(const Point3 &p) = 0;

    virtual void get_xml(pugi::xml_node obj) = 0;

    virtual Ray get_refracted_ray(const Ray &inc_ray, Point3 p, const Vector3 &normale, bool ray_in);
    virtual Ray get_reflected_ray(const Ray &inc_ray, Point3 p, const Vector3 &normale);
};
#endif