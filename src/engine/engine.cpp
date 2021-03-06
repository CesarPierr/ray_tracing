#include "engine/engine.hpp"

Engine::Engine(){};

Engine::Engine(int w, int h) : width(w), height(h){};

int Engine::nb_pixel(int x, int y)
{
    return x + width * y;
}

void Engine::get_pixel(int x, int y, Vector3 &pix)
{
    pix = (*this)[nb_pixel(x, y)];
}

Vector3 Engine::get_color(int x, int y)
{
    float gx = (float)width * pixel_size / 2;
    float gy = (float)height * pixel_size / 2;
    float dx, dy;
    Vector3 c(0.0, 0.0, 0.0);
    Vector3 v_dir;
    Ray r;
    for (int k = 0; k < aa; k++) //get the direction of the ray in the (x,y) pixel
    {
        dx = random_double();
        dy = random_double();
        v_dir = (distance * t - (gx + dx) * b - (gy + dy) * v) + x * pixel_size * b + (height - y) * pixel_size * v;
        r = Ray(pos, v_dir);
        S.compute(r, 0, prof_max);
        c += r.pix.rgb;
    }
    return c * (1 / (float)aa);
}

void Engine::savePicture(const std::string &filename) //save the picture in the ppm format
{
    std::ofstream ofs;
    ofs.open(filename);
    ofs << "P6\n"
        << width << " " << height << "\n255\n";

    for (int i = 0; i < width * height; ++i)
    {
        float exposure = -5.0f;
        (*this)[i][0] = 1.0f - expf((*this)[i][0] * exposure);
        (*this)[i][1] = 1.0f - expf((*this)[i][1] * exposure);
        (*this)[i][2] = 1.0f - expf((*this)[i][2] * exposure);
        (*this)[i] *= 254;
        unsigned char r = (unsigned char)((int)(*this)[i][0]);
        unsigned char g = (unsigned char)((int)(*this)[i][1]);
        unsigned char b = (unsigned char)((int)(*this)[i][2]);

        ofs << r << g << b;
    }
    ofs.close();
}

void Engine::set_scene(Scene &scene) // set the scene
{
    S = scene;
}

void Engine::get_xml(pugi::xml_node sc) 
{
    Materiaux m;

    width = std::atoi(sc.attribute("width").value());
    height = std::atoi(sc.attribute("heigh").value());
    this->reserve(width * height);
    pixel_size = std::atof(sc.attribute("pixel_size").value());

    distance = atof(sc.child("distance_from_screen").child_value());
    float angle = std::atof(sc.child("angle").child_value());
    distance = distance * sqrt((double)(width * height) / (double)(1920 * 1080));
    auto posi = sc.child("pos_viewer");
    float x = std::atof(posi.child("x").child_value());
    float y = std::atof(posi.child("y").child_value());
    float z = std::atof(posi.child("z").child_value());
    pos = Point3(x, y, z);
    auto u1 = sc.child("vector_base").child("u");
    auto u2 = sc.child("vector_base").child("v");
    auto u3 = sc.child("vector_base").child("w");

    x = std::atof(u1.child("x").child_value());
    y = std::atof(u1.child("y").child_value());
    z = std::atof(u1.child("z").child_value());
    x = x * cosf(angle) + z * sinf(angle);
    z = -x * sinf(angle) + z * cosf(angle);
    t = Vector3(x, y, z);

    x = std::atof(u2.child("x").child_value());
    y = std::atof(u2.child("y").child_value());
    z = std::atof(u2.child("z").child_value());
    v = Vector3(x, y, z);

    x = std::atof(u3.child("x").child_value());
    y = std::atof(u3.child("y").child_value());
    z = std::atof(u3.child("z").child_value());
    x = x * cosf(angle) + z * sinf(angle);
    z = -x * sinf(angle) + z * cosf(angle);
    aa = std::atoi(sc.child("antialliasing").child_value());
    prof_max = std::atoi(sc.child("prof_max").child_value());
    b = Vector3(x, y, z);
}