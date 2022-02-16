#ifndef BASE_ENGINE_HPP
#define BASE_ENGINE_HPP
#include "engine.hpp"

// basic engine without parallel programming
class BaseEngine : public Engine
{
public:
    BaseEngine() : Engine(){};
    BaseEngine(int w, int h) : Engine(w, h){};
    void Render(); // launch the raytracing algorithm
};

#endif