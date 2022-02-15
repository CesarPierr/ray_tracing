#ifndef VIEWER_HPP
#define VIEWER_HPP
#include "utils/pointlight.hpp"
#include "scene.hpp"
#include "utils/bitmap_image.hpp"
#include "xml/pugixml.hpp"
#include <omp.h>
#include <random>
#define RATIO 1
#define AA 1

class Engine : public std::vector<Vector3>
{

protected:
    // configuration de base
    int width = 1980 / RATIO;
    int height = 1080 / RATIO;
    Scene S;
    int antialliasing = AA;
    Point3 pos = Point3(0.0, 0.0, 0.0);
    float distance = 1.0 / RATIO;
    float pixel_size = 0.001;
    // base de la matrice de pixel dans l'espace (plan v,b et t direction de regard)
    Vector3 t = Vector3(1.0, 0.0, 0.0), v = Vector3(0.0, 1.0, 0.0), b = Vector3(0.0, 0.0, 1.0);

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