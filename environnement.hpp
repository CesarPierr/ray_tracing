#ifndef ENVIRONNEMENT_HPP
#define ENVIRONNEMENT_HPP
#include "materiaux.hpp"
#include "pointlight.hpp"

class Env
{
    public :
        virtual Color backgroud_color(const Ray& r) = 0;

};

class BaseEnv : public Env
{
    public :
        BaseEnv(){};
        Color backgroud_color(const Ray& r)
        {
            float z = r.dir[1];
            if (z >= 0) 
                return (std::abs(sin(z))*Color(1.0,1.0,1.0)+std::abs(cos(z))*Color(0.0,0.0,1.0))*0.66;
            else
            {
                return Color(0.0,0.0,0.0);
            }
        }

};
#endif