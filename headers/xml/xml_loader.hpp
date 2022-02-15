#ifndef XML_LOADER_HPP
#define XML_LOADER_HPP
#include "engine/base_engine.hpp"
#include "engine/parallele_engine.hpp"
#include "pugixml.hpp"
#include "objet/sphere.hpp"
#include "objet/plan.hpp"
#include "light/buble_light.hpp"
using namespace pugi;

int load_xml(Engine &eng, char *name);

#endif