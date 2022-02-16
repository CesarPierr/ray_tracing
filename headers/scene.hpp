#ifndef SCENE_HPP
#define SCENE_HPP
#include "objet/objet.hpp"
#include "light/light.hpp"
#include "environnement.hpp"
#include <vector>
#include <random>
class Scene
{
public:
    int nb_objet, nb_light;
    std::vector<Objet *> l_objets;
    std::vector<Light *> l_lumieres;
    Env *environnement;

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

    void add_object(Objet &obj);

    void add_light(Light &light);

    void set_env(Env *env);

    int inter(Point3 &pt_inter, const Ray &r, int &type, Vector3 &normale);

    Color get_PON(const Point3 &pt, const Vector3 &normale, const Materiaux &m, const Ray &viewRay);

    float inter_shadow(const Ray &r, float distance_light);

    void compute(Ray &r, int prof, int profmax);
};

#endif