#ifndef COMPLEX_SHAPE_HPP
#define COMPLEX_SHAPE_HPP
#include "objet.hpp"
#include "triangle.hpp"
#include <vector>
class ComplexShape : public Objet // Warning : the triangle list must form a closed object
{
private:
    std::vector<Triangle> l_triangles; // this objet is a lot of triangles together
    Vector3 normale;
    Materiaux in_mat;

public:
    ComplexShape();
    float get_inter(const Ray &r, Point3 &test, Vector3 &normale); // get the intersection between a ray and the light

    Materiaux get_mat(const Point3 &p); // get the material caracteristics of the object

    void get_xml(pugi::xml_node pl); // load this object by xml
};
#endif