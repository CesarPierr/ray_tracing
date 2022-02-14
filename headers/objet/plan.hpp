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

    float get_inter(const Ray &r, Point3 &test);

    Vector3 get_normal(const Point3 &inter);

    bool ray_in(const Ray &r) { return false; }

    Materiaux get_mat(const Point3 &p);

    Ray get_refracted_ray(const Ray &inc_ray, const Point3 &p, const Vector3 &get_normale);

    void get_xml(pugi::xml_node pl);
};
#endif