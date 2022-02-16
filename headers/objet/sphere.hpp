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

    float get_inter(const Ray &r, Point3 &p, Vector3 &normale); // get the intersection between a ray and the light

    Materiaux get_mat(const Point3 &p) // get the material caracteristics of the object
    {
        return mat;
    }

    void get_xml(pugi::xml_node sph); // load this object by xml
};
#endif