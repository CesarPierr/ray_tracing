#ifndef ENVIRONNEMENT_HPP
#define ENVIRONNEMENT_HPP
#include "utils/materiaux.hpp"
#include "utils/pointlight.hpp"

class Env // backgroud limits and color
{
public:
    virtual Color backgroud_color(const Ray &r) = 0;
};

class BaseEnv : public Env // base black environement
{
public:
    BaseEnv(){};
    Color backgroud_color(const Ray &r);
};
#endif