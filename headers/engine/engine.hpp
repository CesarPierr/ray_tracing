#ifndef ENGINE_HPP
#define ENGINE_HPP
#include "utils/pointlight.hpp"
#include "scene.hpp"
#include "xml/pugixml.hpp"
#include <iostream>
#include <fstream>
#include <random>

class Engine : public std::vector<Vector3>
{

protected:
    // configuration de base
    int prof_max;
    int width;
    int height;
    Scene S;
    int aa;
    Point3 pos;
    float distance;
    float pixel_size;
    // base de la matrice de pixel dans l'espace (plan v,b et t direction de regard)
    Vector3 t, v, b;

public:
    Engine();

    Engine(int w, int h);

    int nb_pixel(int x, int y);

    virtual void Render() = 0;

    void get_pixel(int x, int y, Vector3 &pix);

    Vector3 get_color(int x, int y);

    void savePicture(const std::string &filename);

    void set_scene(Scene &scene);

    virtual void get_xml(pugi::xml_node sc);

    inline float random_double()
    {
        static std::uniform_real_distribution<float> distribution(pixel_size / 10, pixel_size);
        static std::mt19937 generator;
        return distribution(generator);
    }
};

#endif