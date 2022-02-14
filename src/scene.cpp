#include "scene.hpp"

float reflectance(float cosine, float ref_idx)
{
    // Use Schlick's approximation for reflectance.
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

void Scene::set_env(Env &env)
{
    *environnement = env;
}

int Scene::inter(Point3 &pt_inter, const Ray &r, int &type)
{
    Point3 test;
    float distance = -1, d_int;
    type = -1;
    int n_obj = -1;

    for (int i = 0; i < nb_objet; i++)
    {
        d_int = l_objets[i]->get_inter(r, test);

        if (d_int != -1 && (d_int < distance || distance == -1))
        {
            pt_inter = test;
            distance = d_int;
            n_obj = i;
            type = 1;
        }
    }

    for (int i = 0; i < nb_light; i++)
    {
        Vector3 L;
        Color c;
        d_int = (*l_lumieres[i]).get_inter_ray(r, test);
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
        float k = L.dot(normale);
        float shadowed = 1;
        Point3 intershadow;

        float reflet = 2.0f * L.dot(normale);
        Vector3 phongDir = L - reflet * normale;

        float phongTerm = std::max(phongDir.dot(viewRay.dir), 0.0f);
        phongTerm = powf(phongTerm, m.shinyness);

        if (k > 0)
        {
            r = Ray(pt, L);
            shadowed = inter_shadow(r, distance);
            retour += (col_lum * m.specular * phongTerm + col_lum * m.diffuse * k * m.coef_diffusion) * shadowed;
        }
    }

    return retour;
}

float Scene::inter_shadow(const Ray &r, float distance_light)
{
    Point3 test;
    float retour = 1;
    for (int i = 0; i < nb_objet; i++)
    {
        float d = (*l_objets[i]).get_inter(r, test);
        if (d >= distance_light || d < 0)
            continue;
        else
            retour *= (*l_objets[i]).mat.coef_refraction;

        if (retour == 0)
            break;
    }
    return retour;
}

void Scene::compute(Ray &r, int prof)
{
    if (prof > prof_max)
        r.pix = Color(0.0, 0.0, 0.0);
    else
    {
        // usefull variables for the recursive ray tracing algorithm
        Point3 pt_inter(0.0, 0.0, 0.0);
        Vector3 normale;
        Ray r_reflexion, r_transmission;
        Materiaux m;
        int type;
        int no_obj = inter(pt_inter, r, type); // get the list position of the first object that intercepts the ray
        if (no_obj == -1)
        {
            r.pix = (*environnement).backgroud_color(r);
        }

        else
        {
            switch (type)
            {
            case 0:
                r.pix = (*l_lumieres[no_obj]).get_color(pt_inter);
                break;
            case 1:
                Objet &current_obj = *l_objets[no_obj];
                normale = current_obj.get_normal(pt_inter);
                m = current_obj.get_mat(pt_inter);

                Color diffuse_spec = get_PON(pt_inter, normale, m, r);
                // load the reflected ray
                float refraction_ratio = current_obj.ray_in(r) ? m.in_refractive_index / m.out_refractive_index : m.out_refractive_index / m.in_refractive_index;
                float sin_theta = std::sqrt(1 - pow(normale.dot(r.dir), 2));

                if (refraction_ratio * sin_theta > 1.0)
                {
                    r_reflexion = current_obj.get_reflected_ray(r, pt_inter, normale);
                    compute(r_reflexion, prof + 1);
                    r.pix = 0.2 * m.ambient + diffuse_spec + (m.coef_reflexion) * r_reflexion.pix;
                }
                else
                {
                    // Can Refract
                    r_reflexion = current_obj.get_reflected_ray(r, pt_inter, normale);
                    r_transmission = current_obj.get_refracted_ray(r, pt_inter, normale);
                    compute(r_reflexion, prof + 1);
                    // load the refracted ray
                    compute(r_transmission, prof + 1);
                    r.pix = 0.2 * m.ambient + diffuse_spec + (m.coef_reflexion) * r_reflexion.pix + (m.coef_refraction) * r_transmission.pix;
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
