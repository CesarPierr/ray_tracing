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
    void maj_normal();                                             // create the normal when asked
    float get_inter(const Ray &r, Point3 &test, Vector3 &normale); // get the intersection between a ray and the light

    Ray get_refracted_ray(const Ray &inc_ray, Point3 p, const Vector3 &normale, bool in); // return the refracted ray on the surface (look snell descarte law)

    Materiaux get_mat(const Point3 &p); // get the material caracteristics of the object

    void get_xml(pugi::xml_node pl); // load this object by xml
};
#endif