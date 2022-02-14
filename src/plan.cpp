#include "objet/plan.hpp"
Plan::Plan() : Pos(Point3(0.0, 0.0, 0.0)), normale(Vector3(1.0, 0.0, 0.0)) {}
Plan::Plan(Point3 p, Vector3 v) : Pos(p), normale(v) {}
Plan::Plan(Point3 p, Vector3 v, Materiaux m) : Pos(p), normale(v) { mat = m; }

float Plan::get_inter(const Ray &r, Point3 &test)
{
    if (normale.dot(r.dir) >= 0)
        return -1;
    else
    {
        float distance_plan = normale.dot(r.src - Pos);
        float t = -distance_plan / (r.dir.dot(normale));
        test = r.src + t * r.dir;
        return t;
    }
}

Vector3 Plan::get_normal(const Point3 &inter)
{
    return normale;
}

Materiaux Plan::get_mat(const Point3 &p)
{
    return mat;
}

Ray Plan::get_refracted_ray(const Ray &inc_ray, const Point3 &p, const Vector3 &get_normale)
{
    Ray r;
    return r;
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
