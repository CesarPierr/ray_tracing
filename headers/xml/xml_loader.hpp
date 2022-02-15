#include "engine/engine.hpp"
#include "pugixml.hpp"
#include "objet/sphere.hpp"
#include "objet/plan.hpp"
#include "light/buble_light.hpp"
using namespace pugi;

int load_xml(Engine &eng, char *name)
{
    Scene *scene = new Scene(); // create the empty scene

    // open the data xml document
    xml_document doc;
    xml_parse_result result = doc.load_file(name);
    if (!result)
        return -1;
    std::cout << "open successfuly" << std::endl;
    auto data = doc.child("RayTracerData");
    auto env = data.child("environnement").child_value();
    auto screen = data.child("Screen");

    // set the sceen parameters
    eng.get_xml(screen);

    // set the environnement
    if (strcmp("base", env) == 0)
    {
        BaseEnv *env = new BaseEnv();
        scene->set_env(*env);
    }

    // add objets and light to the scene
    auto l_objets = data.child("l_objets");
    auto l_lights = data.child("l_light");

    for (auto obj : l_objets)
    {
        if (strcmp(obj.attribute("type").value(), "Sphere") == 0)
        {
            Sphere *sph = new Sphere();
            sph->get_xml(obj);
            scene->add_object(*sph);
        }
        else if (strcmp(obj.attribute("type").value(), "Plan") == 0)
        {
            Plan *pl = new Plan();
            pl->get_xml(obj);
            scene->add_object(*pl);
        }
    }
    for (auto lum : l_lights)
    {
        if ((strcmp(lum.attribute("type").value(), "buble") == 0))
        {
            Buble_light *li = new Buble_light();
            li->get_xml(lum);
            scene->add_light(*li);
        }
    }
    std::cout << scene->l_objets.size() << std::endl;
    eng.set_scene(*scene);
    return 0;
}