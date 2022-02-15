#include "engine/base_engine.hpp"

void BaseEngine::Render()
{

    int avancement = 0;
    int nb_pix = width * height;
    std::cout << "launching base engine" << std::endl;
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            (*this)[nb_pixel(x, y)] = get_color(x, y);
            ++avancement;
            if (avancement % (nb_pix / 100) == 0)
                std::cout << "avancement : " << 100 * avancement / (width * height) << " %" << std::endl;
        }
    }

    savePicture("result.png");
}