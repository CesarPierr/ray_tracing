#ifndef PARALLELE_ENGINE_HPP
#define PARALLELE_ENGINE_HPP
#include "engine.hpp"
#include <omp.h>
class ParalleleEngine : public Engine
{
public:
    int threads = 4;
    ParalleleEngine() : Engine(){};
    ParalleleEngine(int w, int h, int nthread) : Engine(w, h), threads(nthread){};
    void Render();
    void get_xml(pugi::xml_node sc);
};

#endif