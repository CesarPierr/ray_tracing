#ifndef SCENE_HPP
#define SCENE_HPP
#include "objet/objet.hpp"
#include "light/light.hpp"
#include "environnement.hpp"
#include <vector>
#include <random>
class Scene // the scene in which the raytracing algorithm will be launched
{
public:
    int nb_objet, nb_light;
    std::vector<Objet *> l_objets;   // list of scene objets
    std::vector<Light *> l_lumieres; // list of scene lights
    Env *environnement;              // environement of the scene

public:
    Scene() : nb_objet(0),
              nb_light(0){};

    Scene(std::vector<Objet *> obj) : l_objets(obj),
                                      nb_objet(obj.size()),
                                      nb_light(0){};

    Scene(std::vector<Objet *> obj, std::vector<Light *> lum) : l_objets(obj),
                                                                l_lumieres(lum),
                                                                nb_objet(obj.size()),
                                                                nb_light(lum.size()){};

    Scene(std::vector<Objet *> obj, std::vector<Light *> lum, Env *env) : l_objets(obj),
                                                                          l_lumieres(lum),
                                                                          nb_objet(obj.size()),
                                                                          nb_light(lum.size()),
                                                                          environnement(env){};

    ~Scene(){};

    void add_object(Objet &obj); // add an objet

    void add_light(Light &light); // add a light

    void set_env(Env *env); // set the environement

    void compute(Ray &r, int prof, int profmax); // throw a ray in the scene

    int inter(Point3 &pt_inter, const Ray &r, int &type, Vector3 &normale); // return the distance from the src point of the ray and the closer objet/light
                                                                            // as well as getting the intersection point, the type (object/light) and the normal of the hit surface

    Color get_PON(const Point3 &pt, const Vector3 &normale, const Materiaux &m, const Ray &viewRay); // get the illumination following the phong model
                                                                                                     // and material caracteristics : https://en.wikipedia.org/wiki/Phong_reflection_model

    float inter_shadow(const Ray &r, float distance_light); // get the shadows
};

#endif