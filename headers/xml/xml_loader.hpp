#ifndef XML_LOADER_HPP
#define XML_LOADER_HPP
#include "engine/base_engine.hpp"
#include "engine/parallele_engine.hpp"
#include "pugixml.hpp"
#include "objet/sphere.hpp"
#include "objet/plan.hpp"
#include "light/buble_light.hpp"
#include "objet/triangle.hpp"
#include "objet/complex_shape.hpp"
using namespace pugi;

int load_xml(Engine &eng, char *name); // load all the parameters/objects/lights of the engine and the scene from a xml file

#endif