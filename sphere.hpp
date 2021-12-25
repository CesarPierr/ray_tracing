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
            //calcul first refraction direction
            float n1n2 = mat.out_refractive_index/mat.in_refractive_index;
            float a1 = inc_ray.dir.dot(normale);
            float a2 = sqrt(1-n1n2*n1n2*(1-a1*a1));
            Vector3 R = n1n2 * inc_ray.dir-(n1n2*a1 + a2)*normale;
            R = R/R.norm();
            //get the new point inside the sphere
            Vector3 OC = centre-p;
            float OH = OC.dot(R);
            float CH2 = OC.dot(OC)-OH*OH;
            float distance = sqrt(rayon*rayon-CH2);
            float t_min = std::max(OH+distance,OH-distance);
            Point3 inter = R+t_min*R;
            
            //get the last ray
            Vector3 normale2 = get_normal(inter);
            float n2n1 = 1/n1n2;
            a1 = R.dot(normale2);
            a2 = sqrt(1-n2n1*n2n1*(1-a1*a1));
            Vector3 R2 = n2n1 * R-(n2n1*a1 + a2)*normale2;

            Ray retour = Ray(inter,R2);
            return retour;
        }

};
#endif