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
        std::vector<Objet*> l_objets;
        std::vector<Light*> l_lumieres;
        //Env environnement;
        int prof_max = 2;

    public :
        
        Scene() :   nb_objet(0), 
                    nb_light(0) 
        {};

        Scene(std::vector<Objet*> obj) : l_objets(obj), 
                                        nb_objet(obj.size()), 
                                        nb_light(0) 
        {};

        Scene(std::vector<Objet*> obj, std::vector<Light*> lum) : l_objets(obj), 
                                                                l_lumieres(lum), 
                                                                nb_objet(obj.size()), 
                                                                nb_light(lum.size()) 
        {};

        /*Scene(std::vector<Objet> obj, std::vector<Light> lum, Env env) :    l_objets(obj), 
                                                                            l_lumieres(lum), 
                                                                            nb_objet(obj.size()), 
                                                                            nb_light(lum.size()),
                                                                            environnement(env)
        {};
        */

        ~Scene(){};
        void add_object(Objet &obj)
        {
            l_objets.push_back(&obj);
            nb_objet ++;
        }
        void add_light(Light &light)
        {
            l_lumieres.push_back(&light);
            nb_light++;
        }
        /*
        void set_env(Env env)
        {
            environnement = env;
        }
        */
        int inter(Point3 &pt_inter, Ray r, int &type)
        {
            Point3 test;
            float distance = -1, d_int;

            int n_obj = -1;
            for (int i = 0; i< nb_objet;i++)
            {
                d_int = (*l_objets[i]).get_inter(r,test);

                if (d_int != -1 && (d_int < distance || distance == -1))
                {
                    pt_inter = test;
                    n_obj = i;
                }
            }
            for(int i =0; i < nb_light; i++)
            {
                d_int = (*l_lumieres[i]).get_inter()
            }
            return n_obj;
        }
        Color get_PON(const Point3 &pt, const Vector3 & normale, const Materiaux& m)
        {
            Color retour(0.0,0.0,0.0), col_lum;
            Vector3 L;
            for(int i = 0; i< nb_light;i++)
            {
                (*l_lumieres[i]).get_inter(pt,L,col_lum);
                float k = L.dot(normale);

                if(k>0)
                    retour+= col_lum*m.specular*k*m.coef_diffusion;
            }
            return retour;
        }
        void compute(Ray &r, int prof)
        {
            if (prof > prof_max)
                  r.pix =  Color(0.0,0.0,0.0);
            else
            {
                //usefull variables for the recursive ray tracing algorithm
                Point3 pt_inter;
                Vector3 normale;
                Ray r_reflexion, r_transmission;
                Materiaux m;
                int no_obj = inter(pt_inter, r); //get the list position of the first object that intercepts the ray
                if(no_obj == -1){
                    r.pix = Color(0.0,0.0,0.0);
                }
                else
                {
                    Objet &current_obj = *l_objets[no_obj];
                    normale = current_obj.get_normal(pt_inter);
                    normale /= normale.norm();
                    m = current_obj.get_mat(pt_inter);
                    Color diffuse = get_PON(pt_inter,normale,m);
                    //load the reflected ray 
                    /*r_reflexion = current_obj.get_reflected_ray(r,pt_inter,normale);
                    compute(r_reflexion,prof+1);
                    //load the refracted ray
                    r_transmission = current_obj.get_refracted_ray(r,pt_inter,normale);
                    compute(r_transmission, prof+1);
                    
                    */
                    r.pix = m.ambient+diffuse;
                }
            }
        }
};

#endif