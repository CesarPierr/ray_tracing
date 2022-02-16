#include "objet/plan.hpp"
Plan::Plan() : Pos(Point3(0.0, 0.0, 0.0)), normale(Vector3(1.0, 0.0, 0.0)) {}
Plan::Plan(Point3 p, Vector3 v) : Pos(p), normale(v) {}
Plan::Plan(Point3 p, Vector3 v, Materiaux m) : Pos(p), normale(v) { mat = m; }

float Plan::get_inter(const Ray &r, Point3 &test, Vector3 &norm)
{
    Point3 projete = r.src - normale.dot(r.src - Pos) * normale;
    if (r.dir.dot(projete - r.src) < 0)
    {
        // std::cout << "salut" << std::endl;
        return -1;
    }
    else
    {
        normale /= normale.norm();
        float distance_plan = normale.dot(r.src - Pos);
        float t = -distance_plan / (r.dir.dot(normale));
        test = r.src + t * r.dir;
        norm = normale;
        return t;
    }
}

Materiaux Plan::get_mat(const Point3 &p)
{
    return mat;
}
Ray Plan::get_refracted_ray(const Ray &inc_ray, Point3 p, const Vector3 &normale)
{
    // std::cout << p << std::endl;
    Ray refract(inc_ray);
    refract.src = p + 0.001f * inc_ray.dir;
    return refract;
}
void Plan::get_xml(pugi::xml_node pl)
{
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
}
