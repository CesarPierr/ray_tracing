#ifndef BUBLE_LIGHT_HPP
#define BUBLE_LIGHT_HPP
#include "light.hpp"

class Buble_light : public Light
{
    public :
        
        Point3 centre;
        float rayon;


        Buble_light() : centre(Point3(0.0,0.0,0.0)), rayon(1) {}
        Buble_light(Point3 c, float r) : centre(c), rayon(r) {}

        float get_inter(const Point3& p,Vector3& L, Color& c)
        {
            L = centre-p;
            float distance = L.norm();
            L /= L.norm();
            c = light_color;
            return distance - rayon;
        }

        Color get_color(const Point3& p)
        {
            return light_color;
        }

        float get_inter_ray(const Ray& r, Point3 p)
        {
            float distance = -1;
            Vector3 OC = centre-r.src;
            float OH = OC.dot(r.dir);
            if(OH < 0)
                return distance;
            else
            {
                float CH2 = OC.dot(OC)-OH*OH;
                if(CH2 > rayon*rayon)
                    return distance;
                else
                {
                    distance = sqrt(rayon*rayon-CH2);
                    float t_min = std::min(OH+distance,OH-distance);
                    Point3 inter = r.src+t_min*r.dir;
                    p = inter;
                    return t_min;
                }
            }
        }
};  

#endif