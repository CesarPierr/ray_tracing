#include "xml/xml_loader.hpp"
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
    auto engine = data.child("engine");

    // set the sceen parameters

    eng.get_xml(engine);

    // set the environnement
    if (strcmp("base", env) == 0)
    {
        BaseEnv *env = new BaseEnv();
        scene->set_env(env);
    }
    else
    {
        BaseEnv *env = new BaseEnv();
        scene->set_env(env);
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
        else if (strcmp(obj.attribute("type").value(), "Triangle") == 0)
        {
            Triangle *tr = new Triangle();
            tr->get_xml(obj);
            scene->add_object(*tr);
        }
        else if (strcmp(obj.attribute("type").value(), "ComplexShape") == 0)
        {
            ComplexShape *cs = new ComplexShape();
            cs->get_xml(obj);
            scene->add_object(*cs);
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
    eng.set_scene(*scene);
    return 0;
}