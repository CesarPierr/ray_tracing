#ifndef PLAN_HPP
#define PLAN_HPP
#include "objet.hpp"

class Plan : public Objet
{
public:
    Vector3 normale;
    Point3 Pos;

    Plan();
    Plan(Point3 p, Vector3 v);
    Plan(Point3 p, Vector3 v, Materiaux m);

    float get_inter(const Ray &r, Point3 &test, Vector3 &normale); // get the intersection between a ray and the light

    Ray get_refracted_ray(const Ray &inc_ray, Point3 p, const Vector3 &normale, bool in); // return the refracted ray on the surface (look snell descarte law)

    Materiaux get_mat(const Point3 &p); // get the material caracteristics of the object

    void get_xml(pugi::xml_node pl); // load this object by xml
};
#endif