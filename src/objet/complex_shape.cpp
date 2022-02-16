#include "objet/complex_shape.hpp"

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
Ray ComplexShape::get_refracted_ray(const Ray &inc_ray, Point3 p, const Vector3 &normale)
{
    // std::cout << p << std::endl;
    Ray refract(inc_ray);
    refract.src = p + 0.001f * inc_ray.dir;
    return refract;
}
void ComplexShape::get_xml(pugi::xml_node pl) {}
/*{
    pugi::xml_node position = pl.child("centre");
    float x = atof(position.child("x").child_value());
    float y = atof(position.child("y").child_value());
    float z = atof(position.child("z").child_value());
    this->Pos = Point3(x, y, z);

    pugi::xml_node normal = pl.child("normale");
    float u = atof(normal.child("u").child_value());
    float v = atof(normal.child("v").child_value());
    float w = atof(normal.child("w").child_value());
    this->normale = Vector3(u, v, w);

    const char *mat_name = pl.child("Materiaux").child_value();
    this->mat = Materiaux().get_existing_mat(mat_name);
}*/
