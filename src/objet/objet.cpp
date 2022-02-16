#include "objet/objet.hpp"
Ray Objet::get_refracted_ray(const Ray &inc_ray, Point3 p, const Vector3 &normale, bool ray_in)
{
    // std::cout << p << std::endl;
    if (ray_in)
    {
        float eta = mat.in_refractive_index / mat.out_refractive_index;
        float c1 = -normale.dot(inc_ray.dir);
        float c2 = std::sqrt(1 - eta * eta * (1 - c1 * c1));
        Vector3 dir = eta * inc_ray.dir - (eta * c1 - c2) * normale;
        Ray refract(p + 0.001f * dir, dir);
        return refract;
    }
    else
    {
        float eta = mat.out_refractive_index / mat.in_refractive_index;
        float c1 = normale.dot(inc_ray.dir);
        float c2 = std::sqrt(1 - eta * eta * (1 - c1 * c1));
        Vector3 dir = eta * inc_ray.dir + (eta * c1 - c2) * normale;
        Ray refract(p + 0.001f * dir, dir);
        return refract;
    }
}
Ray Objet::get_reflected_ray(const Ray &inc_ray, Point3 p, const Vector3 &normale)
{
    Vector3 dir_reflec = inc_ray.dir - (2 * normale.dot(inc_ray.dir) * normale);
    Ray reflec(p + 0.001f * dir_reflec, dir_reflec);
    return reflec;
}