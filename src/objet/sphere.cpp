#include "objet/sphere.hpp"

Sphere::Sphere() : centre(Point3(0.0, 0.0, 0.0)), rayon(1){};

Sphere::Sphere(Point3 c, float r) : centre(c), rayon(r){};

Sphere::Sphere(Point3 c, float r, Materiaux m) : centre(c), rayon(r) { (*this).mat = m; };

float Sphere::get_inter(const Ray &r, Point3 &p, Vector3 &norm)
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
            if ((rayon * rayon - OC.dot(OC)) >= 0)
                t_min = std::max(OH + distance, OH - distance);
            t_min += 0.01;
            Point3 inter = r.src + t_min * r.dir;
            norm = inter - centre;
            norm *= (1 / norm.norm());
            p = inter;
            return t_min;
        }
    }
}

bool Sphere::ray_in(const Ray &r)
{
    float distance = (r.src - centre).norm();
    if (distance < rayon)
        return true;
    return false;
}

void Sphere::get_xml(pugi::xml_node sph)
{
    pugi::xml_node position = sph.child("centre");
    float x = atof(position.child("x").child_value());
    float y = atof(position.child("y").child_value());
    float z = atof(position.child("z").child_value());
    this->centre = Point3(x, y, z);

    float r = atof(sph.child("rayon").child_value());
    this->rayon = r;

    const char *mat_name = sph.child("Materiaux").child_value();
    this->mat = Materiaux().get_existing_mat(mat_name);
}
