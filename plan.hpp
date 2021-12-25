#ifndef PLAN_HPP
#define PLAN_HPP
#include "objet.hpp"

class Plan : public Objet
{
    public :
        Vector3 normale;
        Point3 Pos;

        Plan(Point3 p, Vector3 v) : Pos(p), normale(v) {}
        Plan(Point3 p, Vector3 v, Materiaux m) : Pos(p), normale(v) {mat = m; }

        float get_inter(const Ray &r, Point3 &test)
        {
            if(normale.dot(r.dir) >=0 )
                return -1;
            else
            {
                float distance_plan = - normale.dot(Pos-r.src);
                float cos_angle = -r.dir.dot(normale)/r.dir.norm();
                float retour = distance_plan/cos_angle;
                test = retour*r.dir/r.dir.norm();
                return retour;
            }
        }
        
        Vector3 get_normal(const Point3& inter)
        {
            return normale;
        }

        Materiaux get_mat(const Point3& p)
        {
            return mat;
        }

        Ray get_refracted_ray(const Ray &inc_ray, const Point3& p, const Vector3& get_normale)
        {
            Ray r;
            r.puissance = 0;
            return r;
        }
};
#endif