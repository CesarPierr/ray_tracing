#include "engine/parallele_engine.hpp"

void ParalleleEngine::Render()
{

    int avancement = 0;
    int nb_pix = width * height;
    std::cout << "launching parallel engine" << std::endl;
#pragma omp parallel shared(avancement) num_threads(threads)
    {
#pragma omp for schedule(static, 100)
        for (int x = 0; x < width; x++)
        {

            for (int y = 0; y < height; y++)
            {
                (*this)[nb_pixel(x, y)] = get_color(x, y);
                ++avancement;
            }
        }
    }
    savePicture("result.ppm");
}

void ParalleleEngine::get_xml(pugi::xml_node sc)
{
    threads = std::atoi(sc.child("nthread").child_value());
    Engine::get_xml(sc);
}