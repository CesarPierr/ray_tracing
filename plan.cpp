#include "plan.hpp"

Plan::Plan(Point3 p, Vector3 v) : Pos(p), normale(v) {}
Plan::Plan(Point3 p, Vector3 v, Materiaux m) : Pos(p), normale(v) { mat = m; }

float Plan::get_inter(const Ray &r, Point3 &test)
{
    if (normale.dot(r.dir) >= 0)
        return -1;
    else
    {
        float distance_plan = normale.dot(r.src-Pos);
        float t = -distance_plan/(r.dir.dot(normale));
        test = r.src+t*r.dir;
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