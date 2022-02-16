#ifndef ENGINE_HPP
#define ENGINE_HPP
#include "utils/pointlight.hpp"
#include "scene.hpp"
#include "xml/pugixml.hpp"
#include <iostream>
#include <fstream>
#include <random>

// source engine is a big grid of pixels with methods to calcul it
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

    int nb_pixel(int x, int y); // transform coor of 2 dim array to 1 dim array

    virtual void Render() = 0; // launch the raytracing algorithm

    void get_pixel(int x, int y, Vector3 &pix); // calcul the final color of one pixel

    Vector3 get_color(int x, int y); // calcul the final color of one pixel

    void savePicture(const std::string &filename);

    void set_scene(Scene &scene); // add the scene in which the raytracing algorithm will be launched

    virtual void get_xml(pugi::xml_node sc); // use xml to get the parameters

    inline float random_double() // usefull for antialiasing
    {
        static std::uniform_real_distribution<float> distribution(pixel_size / 10, pixel_size);
        static std::mt19937 generator;
        return distribution(generator);
    }
};

#endif