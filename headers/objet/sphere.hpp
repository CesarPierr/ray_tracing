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

    float get_inter(const Ray &r, Point3 &p, Vector3 &normale);

    bool ray_in(const Ray &r);
    Materiaux get_mat(const Point3 &p)
    {
        return mat;
    }

    void get_xml(pugi::xml_node sph);
};
#endif