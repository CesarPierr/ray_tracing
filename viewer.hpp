#ifndef VIEWER_HPP
#define VIEWER_HPP
#include "pointlight.hpp"
#include "scene.hpp"
#include "bitmap_image.hpp"
#include <omp.h>
#include <random>
#define RATIO 2
#define AA 1


class Screen : public std::vector<Vector3>
{
public:
    int width = 1980/RATIO;
    int height = 1080/RATIO;
    Scene S;
    int antialliasing = AA;
    Point3 pos = Point3(0.0, 0.0, 0.0);
    float distance = 1.0/RATIO;
    float pixel_size = 0.001;
    // base de la matrice de pixel dans l'espace (plan v,b et t direction de regard)
    Vector3 t = Vector3(1.0, 0.0, 0.0), v = Vector3(0.0, 1.0, 0.0), b = Vector3(0.0, 0.0, 1.0);

public:
    Screen();

    Screen(int w, int h);

    int nb_pixel(int x, int y);

    void Render();

    void get_pixel(int x, int y, Vector3 &pix);

    Vector3 get_color(int x, int y);

    void savePicture(const std::string &filename);

    inline float random_double() {
        static std::uniform_real_distribution<float> distribution(pixel_size/10,pixel_size);
        static std::mt19937 generator;
        return distribution(generator);
    }
};

#endif