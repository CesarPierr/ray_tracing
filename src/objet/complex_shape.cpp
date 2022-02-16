#include "objet/complex_shape.hpp"

ComplexShape::ComplexShape(){};
float ComplexShape::get_inter(const Ray &r, Point3 &pt_inter, Vector3 &normale)
{
    float distance = -1, d_int;
    int n_obj = -1;
    Point3 test, norm_int;
    for (int i = 0; i < l_triangles.size(); i++)
    {
        d_int = l_triangles[i].get_inter(r, test, norm_int);

        if (d_int != -1 && (d_int < distance || distance == -1))
        {
            normale = norm_int;
            pt_inter = test;
            distance = d_int;
            n_obj = i;
        }
    }
    if (r.dir.dot(normale) < 0)
        normale = Vector3(0.0, 0.0, 0.0) - normale;
    return distance;
}

Materiaux ComplexShape::get_mat(const Point3 &p)
{
    return in_mat;
}

void ComplexShape::get_xml(pugi::xml_node pl)
{
    auto triangles = pl.child("l_triangles");
    for (auto triangle : triangles)
    {
        Triangle t;
        t.get_xml(triangle);
        l_triangles.push_back(t);
    }
    const char *mat_name = pl.child("Materiaux").child_value();

    this->in_mat = Materiaux().get_existing_mat(mat_name);
    this->mat = Materiaux().get_existing_mat(mat_name);
    std::cout << in_mat.ambient.rgb << std::endl;
}
