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

    virtual float get_inter(const Ray &r, Point3 &test, Vector3 &normale) = 0; // get the intersection between a ray and the light
    virtual Materiaux get_mat(const Point3 &p) = 0;                            // get the material caracteristics of the object

    virtual void get_xml(pugi::xml_node obj) = 0; // load this object by xml

    virtual Ray get_refracted_ray(const Ray &inc_ray, Point3 p, const Vector3 &normale, bool ray_in); // return the refracted ray on the surface (look snell descarte law)
    virtual Ray get_reflected_ray(const Ray &inc_ray, Point3 p, const Vector3 &normale);              // return the reflected ray on the surface
};
#endif