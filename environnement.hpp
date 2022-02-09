#ifndef ENVIRONNEMENT_HPP
#define ENVIRONNEMENT_HPP
#include "materiaux.hpp"
#include "pointlight.hpp"

class Env
{
public:
    virtual Color backgroud_color(const Ray &r) = 0;
};

class BaseEnv : public Env
{
public:
    BaseEnv(){};
    Color backgroud_color(const Ray &r);
};
#endif