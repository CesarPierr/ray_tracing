#include "light/buble_light.hpp"

Buble_light::Buble_light() : centre(Point3(0.0, 0.0, 0.0)), rayon(1) { power = low_dispersion; }

Buble_light::Buble_light(Point3 c, float r) : centre(c), rayon(r) { power = low_dispersion; }

float Buble_light::get_inter(const Point3 &p, Vector3 &L, Color &c)
{
    L = centre - p;
    float distance = L.norm();
    L /= distance;
    c = get_color(p, distance);
    return distance - rayon;
}

float Buble_light::get_inter_ray(const Ray &r, Point3 p)
{
    float distance = -1;
    Vector3 OC = centre - r.src;
    float OH = OC.dot(r.dir);
    if (OH < 0)
        return distance;
    else
    {

        float CH2 = OC.dot(OC) - OH * OH;
        if (CH2 - rayon * rayon > 0.01)
        {
            return distance;
        }
        else
        {
            distance = sqrt(abs(rayon * rayon - CH2));
            float t_min = std::min(OH + distance, OH - distance);
            Point3 inter = r.src + t_min * r.dir;
            p = inter;
            return t_min;
        }
    }
}

void Buble_light::get_xml(pugi::xml_node bl)
{
    pugi::xml_node position = bl.child("position");
    float x = atof(position.child("x").child_value());
    float y = atof(position.child("y").child_value());
    float z = atof(position.child("z").child_value());
    this->centre = Point3(x, y, z);

    pugi::xml_node col = bl.child("color");
    float r = atof(col.child("r").child_value());
    float g = atof(col.child("g").child_value());
    float b = atof(col.child("b").child_value());
    this->light_color = Color(r, g, b);

    this->rayon = atof(bl.child("rayon").child_value());
}
