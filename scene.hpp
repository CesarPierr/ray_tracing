#ifndef SCENE_HPP
#define SCENE_HPP
#include "objet.hpp"
#include "light.hpp"
#include "environnement.hpp"
#include <vector>
class Scene
{
    private :
        int nb_objet,nb_light;
        std::vector<Objet> l_objets;
        std::vector<Light> l_lumieres;
        Env environnement;

    public :
        
        Scene() :   nb_objet(0), 
                    nb_light(0) 
        {};

        Scene(std::vector<Objet> obj) : l_objets(obj), 
                                        nb_objet(obj.size()), 
                                        nb_light(0) 
        {};

        Scene(std::vector<Objet> obj, std::vector<Light> lum) : l_objets(obj), 
                                                                l_lumieres(lum), 
                                                                nb_objet(obj.size()), 
                                                                nb_light(light.size()) 
        {};

        Scene(std::vector<Objet> obj, std::vector<Light> lum, Env env) :    l_objets(obj), 
                                                                            l_lumieres(lum), 
                                                                            nb_objet(obj.size()), 
                                                                            nb_light(lum.size()),
                                                                            environnement(env)

        {};

        void add_object(Objet obj)
        {
            l_objets.push_back(obj);
            nb_objet ++;
        }
        void add_light(Light light)
        {
            l_lumieres.push_back(light);
            nb_light++;
        }
        void set_env(Env env)
        {
            environnement(env);
        }
        
};

#endif