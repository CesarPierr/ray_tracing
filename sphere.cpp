#include "sphere.hpp"

Sphere::Sphere() : centre(Point3(0.0, 0.0, 0.0)), rayon(1){};

Sphere::Sphere(Point3 c, float r) : centre(c), rayon(r){};

Sphere::Sphere(Point3 c, float r, Materiaux m) : centre(c), rayon(r) { (*this).mat = m; };


Vector3 Sphere::get_normal(const Point3 &inter)
{
    Vector3 n = inter - centre;
    
    return n*(1/n.norm());
}

float Sphere::get_inter(const Ray &r, Point3 &p)
{
    float distance = -1;
    Vector3 OC = centre - r.src;
    float OH = OC.dot(r.dir);
    if (OH < 0)
        return distance;
    else
    {
        float CH2 = OC.dot(OC) - OH * OH;
        if (CH2 > rayon * rayon)
            return distance;
        else
        {
            distance = sqrt(rayon * rayon - CH2);
            float t_min = std::min(OH + distance, OH - distance);
            if ((rayon*rayon - OC.dot(OC))>= 0)
                t_min = std::max(OH + distance, OH - distance);
            t_min += 0.01;
            Point3 inter = r.src + t_min * r.dir;
            p = inter;
            return t_min;
        }
    }
}

bool Sphere::ray_in(const Ray & r)
{
    float distance = (r.src-centre).norm();
    if (distance < rayon)
        return true;
    return false;
}
