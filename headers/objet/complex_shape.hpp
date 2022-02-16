#ifndef COMPLEX_SHAPE_HPP
#define COMPLEX_SHAPE_HPP
#include "objet.hpp"
#include "triangle.hpp"
#include <vector>
class Complex : public Objet
{
private:
    std::vector<Triangle> l_triangles;

public:
    Complex();
    float get_inter(const Ray &r, Point3 &test);

    Vector3 get_normal(const Point3 &inter);

    Ray get_refracted_ray(const Ray &inc_ray, Point3 p, const Vector3 &normale);

    bool ray_in(const Ray &r) { return false; }

    Materiaux get_mat(const Point3 &p);

    void get_xml(pugi::xml_node pl);
};
#endif