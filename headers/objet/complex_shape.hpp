#ifndef COMPLEX_SHAPE_HPP
#define COMPLEX_SHAPE_HPP
#include "objet.hpp"
#include "triangle.hpp"
#include <vector>
class ComplexShape : public Objet
{
private:
    std::vector<Triangle> l_triangles;
    Vector3 normale;
    Materiaux in_mat;

public:
    ComplexShape();
    float get_inter(const Ray &r, Point3 &test, Vector3 &normale);

    Materiaux get_mat(const Point3 &p);

    void get_xml(pugi::xml_node pl);
};
#endif