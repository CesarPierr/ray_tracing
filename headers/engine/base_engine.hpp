#ifndef BASE_ENGINE_HPP
#define BASE_ENGINE_HPP
#include "engine.hpp"

class BaseEngine : public Engine
{
public:
    BaseEngine() : Engine(){};
    BaseEngine(int w, int h) : Engine(w, h){};
    void Render();
};

#endif