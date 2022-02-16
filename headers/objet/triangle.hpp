#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "objet.hpp"

class Triangle : public Objet
{
private:
    Point3 A, B, C;
    Vector3 normale;

public:
    Triangle();
    Triangle(Point3 a, Point3 b, Point3 c);
    Triangle(Point3 a, Point3 b, Point3 c, Materiaux m);
    void maj_normal();
    float get_inter(const Ray &r, Point3 &test, Vector3 &normale);

    Vector3 get_normal(const Point3 &inter);

    Ray get_refracted_ray(const Ray &inc_ray, Point3 p, const Vector3 &normale);

    bool ray_in(const Ray &r) { return false; }

    Materiaux get_mat(const Point3 &p);

    void get_xml(pugi::xml_node pl);
};
#endif