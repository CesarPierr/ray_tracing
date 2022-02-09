#ifndef MATERIAUX_HPP
#define MATERIAUX_HPP
#include "color.hpp"
class Materiaux // utilisation des modeles informatiques des caracteristiques optique des matériaux
{
public:
    Color ambient;
    Color diffuse;
    Color specular;

    float shinyness;      // specular
    float coef_diffusion; // k_diffus
    float coef_reflexion;
    float coef_refraction;
    float in_refractive_index;
    float out_refractive_index;

    static Materiaux mix(float t, const Materiaux &m1, const Materiaux &m2)
    {
        Materiaux m;
        float s = 1.0f - t;

        m.ambient = s * m1.ambient + t * m2.ambient;
        m.diffuse = s * m1.diffuse + t * m2.diffuse;
        m.specular = s * m1.specular + t * m2.specular;
        m.shinyness = s * m1.shinyness + t * m2.shinyness;
        m.coef_diffusion = s * m1.coef_diffusion + t * m2.coef_diffusion;
        m.coef_reflexion = s * m1.coef_reflexion + t * m2.coef_reflexion;
        m.coef_refraction = s * m1.coef_refraction + t * m2.coef_refraction;
        m.in_refractive_index = s * m1.in_refractive_index + t * m2.in_refractive_index;
        m.out_refractive_index = s * m1.out_refractive_index + t * m2.out_refractive_index;
        return m;
    }

    static Materiaux redPlastic()
    {
        Materiaux m;
        m.ambient = Color(0.1f, 0.0f, 0.0f);
        m.diffuse = Color(0.85f, 0.05f, 0.05f);
        m.specular = Color(1.0, 0.8, 0.8);
        m.shinyness = 5.0f;
        m.coef_diffusion = 1.0f;
        m.coef_reflexion = 0.05f;
        m.coef_refraction = 0.0f;
        m.in_refractive_index = 1.0f;
        m.out_refractive_index = 1.0f;
        return m;
    }

    static Materiaux bronze()
    {
        Materiaux m;
        m.ambient = Color(0.1125, 0.0675, 0.054);
        m.diffuse = Color(0.714, 0.4284, 0.18144);
        m.specular = Color(0.9, 0.8, 0.7);
        // m.specular  = Color( 0.393548, 0.271906, 0.166721 );
        m.shinyness = 56; // 25.6;
        m.coef_diffusion = 0.5f;
        m.coef_reflexion = 0.75f;
        m.coef_refraction = 0.0f;
        m.in_refractive_index = 1.0f;
        m.out_refractive_index = 1.0f;
        return m;
    }

    static Materiaux emerald()
    {
        Materiaux m;
        m.ambient = Color(0.0f, 0.01f, 0.0f); // Color( 0.0215, 0.1745, 0.0215 );
        m.diffuse = Color(0.09568f, 0.77424f, 0.10f);
        m.specular = Color(0.9, 1.0, 0.9); // Color( 0.633, 0.727811, 0.633 );
        m.shinyness = 0.6 * 128.0f;
        m.coef_diffusion = 0.15f;
        m.coef_reflexion = 0.5f;
        m.coef_refraction = 0.65f;
        m.in_refractive_index = 1.5f;
        m.out_refractive_index = 1.0f;
        return m;
    }

    static Materiaux emerald_green()
    {
        Materiaux m;
        m.ambient = Color(0.0f, 0.05f, 0.0f); // Color( 0.0215, 0.1745, 0.0215 );
        m.diffuse = Color(0.1, 0.77, 0.10);
        m.specular = Color(0.9, 1.0, 0.9); // Color( 0.633, 0.727811, 0.633 );
        m.shinyness = 0.6 * 128.0;
        m.coef_diffusion = 0.3f;
        m.coef_reflexion = 0.5f;
        m.coef_refraction = 0.5f;
        m.in_refractive_index = 1.5f;
        m.out_refractive_index = 1.0f;
        return m;
    }

    static Materiaux emerald_red()
    {
        Materiaux m;
        m.ambient = Color(0.2f, 0.05f, 0.0f); // Color( 0.0215, 0.1745, 0.0215 );
        m.diffuse = Color(0.77f, 0.1f, 0.10f);
        m.specular = Color(0.9, 1.0, 0.9); // Color( 0.633, 0.727811, 0.633 );
        m.shinyness = 0.6 * 128.0;
        m.coef_diffusion = 0.3f;
        m.coef_reflexion = 0.5f;
        m.coef_refraction = 0.5f;
        m.in_refractive_index = 1.5f;
        m.out_refractive_index = 1.0f;
        return m;
    }

    static Materiaux glass()
    {
        Materiaux m;
        m.ambient = Color(0.0, 0.0, 0.0);
        m.diffuse = Color(0.95, 0.95, 1.0);
        m.specular = Color(1.0, 1.0, 1.0);
        m.shinyness = 80.0f;
        m.coef_diffusion = 0.01f;
        m.coef_reflexion = 0.05f;
        m.coef_refraction = 0.50f;
        m.in_refractive_index = 1.5f;
        m.out_refractive_index = 1.0f;
        return m;
    }

    static Materiaux moquette_moche()
    {
        Materiaux m;
        m.ambient = Color(0.05, 0.1, 0.01);
        m.diffuse = Color(0.35, 0.35, 0.35);
        m.specular = Color(1.0, 1.0, 1.0);
        m.shinyness = 3.0f;
        m.coef_diffusion = 1.0f;
        m.coef_reflexion = 0.0f;
        m.coef_refraction = 0.0f;
        m.in_refractive_index = 1.5f;
        m.out_refractive_index = 1.0f;
        return m;
    }
    static Materiaux moquette_bleue()
    {
        Materiaux m;
        m.ambient = Color(0.0, 0.0, 0.1);
        m.diffuse = Color(0.05, 0.05, 0.85);
        m.specular = Color(0.5, 0.5, 0.5);
        m.shinyness = 255.0f;
        m.coef_diffusion = 0.7f;
        m.coef_reflexion = 0.0f;
        m.coef_refraction = 0.0f;
        m.in_refractive_index = 1.5f;
        m.out_refractive_index = 1.0f;
        return m;
    }

    static Materiaux moquette_verte()
    {
        Materiaux m;
        m.ambient = Color(0.0, 0.1, 0.0);
        m.diffuse = Color(0.05, 0.85, 0.05);
        m.specular = Color(1.0, 1.0, 1.0);
        m.shinyness = 255.0f;
        m.coef_diffusion = 0.7f;
        m.coef_reflexion = 0.0f;
        m.coef_refraction = 0.0f;
        m.in_refractive_index = 1.5f;
        m.out_refractive_index = 1.0f;
        return m;
    }

    static Materiaux moquette_jaune()
    {
        Materiaux m;
        m.ambient = Color(0.0, 0.1, 0.1);
        m.diffuse = Color(0.05, 0.75, 0.75);
        m.specular = Color(0.5, 0.5, 0.5);
        m.shinyness = 6.0f;
        m.coef_diffusion = 0.7f;
        m.coef_reflexion = 0.0f;
        m.coef_refraction = 0.0f;
        m.in_refractive_index = 1.5f;
        m.out_refractive_index = 1.0f;
        return m;
    }

    static Materiaux moquette_blanche()
    {
        Materiaux m;
        m.ambient = Color(0.1, 0.1, 0.1);
        m.diffuse = Color(0.85, 0.85, 0.85);
        m.specular = Color(1.0, 1.0, 1.0);
        m.shinyness = 6.0f;
        m.coef_diffusion = 0.7f;
        m.coef_reflexion = 0.0f;
        m.coef_refraction = 0.0f;
        m.in_refractive_index = 1.5f;
        m.out_refractive_index = 1.0f;
        return m;
    }
    static Materiaux moquette_rouge()
    {
        Materiaux m;
        m.ambient = Color(0.1, 0.0, 0.0);
        m.diffuse = Color(0.85, 0.05, 0.05);
        m.specular = Color(0.5, 0.5, 0.5);
        m.shinyness = 255.0f;
        m.coef_diffusion = 0.7f;
        m.coef_reflexion = 0.0f;
        m.coef_refraction = 0.0f;
        m.in_refractive_index = 1.5f;
        m.out_refractive_index = 1.0f;
        return m;
    }

    static Materiaux moquette_mirroir()
    {
        Materiaux m;
        m.ambient = Color(0.0, 0.0, 0.0);
        m.diffuse = Color(1.0, 1.0, 1.0);
        m.specular = Color(1.0, 1.0, 1.0);
        m.shinyness = 50.0f;
        m.coef_diffusion = 0.0f;
        m.coef_reflexion = 1.0f;
        m.coef_refraction = 0.0f;
        m.in_refractive_index = 0.0f;
        m.out_refractive_index = 0.0f;
        return m;
    }
};
#endif