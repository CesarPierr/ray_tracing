#include "scene.hpp"

float reflectance(float cosine, float ref_idx)
{
    // Use Schlick's approximation for reflectance. (coef of refraction and reflextion)
    auto r0 = (1 - ref_idx) / (1 + ref_idx);
    r0 = r0 * r0;
    return r0 + (1 - r0) * pow((1 - cosine), 5);
}

float random_float(float max)
{
    static std::uniform_real_distribution<float> distribution(0, max);
    static std::mt19937 generator;
    return distribution(generator);
}

void Scene::set_env(Env *env)
{
    environnement = env;
}

int Scene::inter(Point3 &pt_inter, const Ray &r, int &type, Vector3 &normale)
{
    Point3 test, n_int;
    float distance = -1, d_int;
    type = -1;
    int n_obj = -1;
    //test the intersection among the list of objets
    for (int i = 0; i < nb_objet; i++)
    {
        d_int = l_objets[i]->get_inter(r, test, n_int);

        if (d_int != -1 && (d_int < distance || distance == -1))
        {
            normale = n_int;
            pt_inter = test;
            distance = d_int;
            n_obj = i;
            type = 1;
        }
    }
    //test the intersection among the list of lights

    for (int i = 0; i < nb_light; i++)
    {
        Vector3 L;
        Color c;
        d_int = l_lumieres[i]->get_inter_ray(r, test);
        if (d_int != -1 && (d_int < distance || distance == -1))
        {
            pt_inter = test;
            n_obj = i;
            type = 0;
        }
    }
    return n_obj;
}

Color Scene::get_PON(const Point3 &pt, const Vector3 &normale, const Materiaux &m, const Ray &viewRay)
{
    Color retour(0.0, 0.0, 0.0), col_lum;
    Vector3 L;
    Ray r;
    for (int i = 0; i < nb_light; i++)
    {
        float distance = (*l_lumieres[i]).get_inter(pt, L, col_lum);
        //phong diffuse coef
        float k = L.dot(normale);
        float shadowed = 1;
        Point3 intershadow;

        float reflet = 2.0f * L.dot(normale);
        Vector3 phongDir = L - reflet * normale;
        //phong specular term
        float phongTerm = std::max(phongDir.dot(viewRay.dir), 0.0f);
        phongTerm = powf(phongTerm, m.shinyness);

        if (k > 0)
        {
            r = Ray(pt, L);
            r.has_been_reflected = viewRay.has_been_reflected;
            //calcul the shadow coef
            shadowed = inter_shadow(r, distance);
            retour += (col_lum * m.specular * phongTerm + col_lum * m.diffuse * k * m.coef_diffusion) * shadowed;
        }
    }

    return retour;
}

float Scene::inter_shadow(const Ray &r, float distance_light)
{
    Point3 test, normale;
    float retour = 1;
    for (int i = 0; i < nb_objet; i++)
    {
        if (r.has_been_reflected == i)
            continue;
        float d = (*l_objets[i]).get_inter(r, test, normale);
        if (d >= distance_light || d < 0)
            continue;
        else
        {
            retour *= (*l_objets[i]).mat.coef_refraction;
        }

        if (retour == 0)
            break;
    }
    return retour;
}

void Scene::compute(Ray &r, int prof, int profmax)
{
    if (prof > profmax)
        r.pix = Color(0.0, 0.0, 0.0);
    else
    {
        // usefull variables for the recursive ray tracing algorithm
        Point3 pt_inter(0.0, 0.0, 0.0);
        Vector3 normale;
        Ray r_reflexion, r_transmission;
        Materiaux m;
        int type;
        int no_obj = inter(pt_inter, r, type, normale); // get the list position of the first object that intercepts the ray
        if (no_obj == -1)
        {
            r.pix = (*environnement).backgroud_color(r);
            std::cout << no_obj << std::endl;
        }

        else
        {
            switch (type)
            {
            case 0: //if the ray intersect a light
                r.pix = (*l_lumieres[no_obj]).get_color(pt_inter);
                break;
            case 1://if the ray intersect an objet

                Objet &current_obj = *l_objets[no_obj];
                //get the material
                m = current_obj.get_mat(pt_inter);

                r.has_been_reflected = no_obj;
                //get the color based on phong model
                Color diffuse_spec = get_PON(pt_inter, normale, m, r);

                //depend if the ray is in or out the intersected objet
                float refraction_ratio = r.has_been_refracted == no_obj ? m.in_refractive_index / m.out_refractive_index : m.out_refractive_index / m.in_refractive_index;
                

                float sin_theta = std::sqrt(1 - pow(normale.dot(r.dir), 2));

                if (refraction_ratio * sin_theta > 1.0) //look if there is a refraction and reflection or only reflection
                {
                    //can't refract
                    r_reflexion = current_obj.get_reflected_ray(r, pt_inter, normale);
                    //  load the reflected ray
                    compute(r_reflexion, prof + 1, profmax);
                    r.pix = 0.2 * m.ambient + diffuse_spec + (m.coef_reflexion) * r_reflexion.pix;
                }
                else
                {
                    // Can Refract
                    if (r.puissance * m.coef_reflexion > 0.05)//look if the new power of the ray is sufficient to be computed again
                    {
                        r_reflexion = current_obj.get_reflected_ray(r, pt_inter, normale);
                        r_transmission.puissance = r.puissance * m.coef_reflexion;
                        r_reflexion.has_been_reflected = no_obj;
                        //  load the reflected ray
                        compute(r_reflexion, prof + 1, profmax);
                    }
                    else
                    {
                        r_reflexion.pix = Color(0.0, 0.0, 0.0);
                    }
                    if (r.puissance * m.coef_refraction > 0.05)//idem for the refraction ray
                    {
                        r_transmission = current_obj.get_refracted_ray(r, pt_inter, normale, r.has_been_refracted == no_obj);
                        r_transmission.puissance = r.puissance * m.coef_refraction;
                        r_transmission.has_been_refracted = no_obj;
                        //  load the refracted ray
                        compute(r_transmission, prof + 1, profmax);
                    }
                    else
                    {
                        r_transmission.pix = Color(0.0, 0.0, 0.0);
                    }

                    
                    //get the final color
                    r.pix = 0.2 * m.ambient + diffuse_spec+ (m.coef_refraction) * r_transmission.pix+ (m.coef_reflexion) * r_reflexion.pix;
                }

                break;
            }
        }
    }
}
void Scene::add_object(Objet &obj)
{
    l_objets.push_back(&obj);
    nb_objet++;
}
void Scene::add_light(Light &light)
{
    l_lumieres.push_back(&light);
    nb_light++;
}
