#ifndef SPHERE_HPP
#define SPHERE_HPP
#include "objet.hpp"

class Sphere : public Objet
{

    public :
        Point3 centre;
        float rayon;

        Sphere() : centre(Point3(0.0,0.0,0.0)), rayon(1) {};
        Sphere(Point3 c, float r) : centre(c), rayon(r) {};
        Sphere(Point3 c, float r, Materiaux m) : centre(c), rayon(r){(*this).mat = m;};
        ~Sphere(){};

        float get_inter(const Ray& r, Point3& p)
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

        Materiaux get_mat(const Point3& p)
        {
            return mat;
        }

        Vector3 get_normal(const Point3& inter)
        {
            Vector3 n = inter-centre;
            return n;
        }
        Ray get_refracted_ray(const Ray &inc_ray,const Point3& p,const Vector3& normale)
        {
            return Ray();
        }

};
#endif